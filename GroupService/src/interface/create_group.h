#pragma once

#include "lightrpc/net/rpc/rpc_interface.h"
#include "lightrpc/common/exception.h"
#include "../proto/GroupServer.pb.h"
#include "../proto/GroupService.pb.h"
#include "../service/ZooKeeperMaster.h"
#include <cstdio>
#include <string>

#define BUFF_SIZE 256

class CreateGroupImpl : public lightrpc::RpcInterface{
public:
    CreateGroupImpl(const google::protobuf::Message* req, google::protobuf::Message* rsp, google::protobuf::RpcController* controller, ::google::protobuf::Closure* done):
    lightrpc::RpcInterface(req, rsp, controller, done){}

    void Run(){
        try {
            // 初始化请求和响应
            auto req = dynamic_cast<const ik_ChatService::CreateGroupRequest*>(m_req_base_);
            auto res = dynamic_cast<ik_ChatService::CreateGroupResponse*>(m_rsp_base_);

            //刷新zookeeper列表
            ZKMatser::getInstance()->get_follow();
            //反序列化
            ik_ChatServer::Request send_request;
            //重新序列化
            send_request.set_type("CreateGroup");
            send_request.set_request_msg(req->SerializeAsString());

            //获得一个可用的连接
            string send_str = send_request.SerializeAsString();
            int client_fd;
            while ((client_fd =  ZKMatser::getInstance()->get_service()) == -1)
            {
                 ZKMatser::getInstance()->get_follow();
                sleep(1);
            }

            //发送任务信息
            if (send(client_fd, send_str.c_str(), send_str.size(), 0) == -1){
                throw "creategroup command send error";
            }
            char recv_buf[BUFF_SIZE] = {0};
            if (recv(client_fd, recv_buf, BUFF_SIZE, 0) == -1){
                throw "creategroup command recv error";
            }
            res->ParseFromString(recv_buf);
            close(client_fd);
        }catch (lightrpc::LightrpcException& e) {
            LOG_APPERROR("LightrpcException exception[%s], deal handle", e.what());
            e.handle();
            SetError(e.errorCode(), e.errorInfo());
        } catch (std::exception& e) {
            LOG_APPERROR("std::exception[%s], deal handle", e.what());
            SetError(-1, "unkonwn std::exception");
        } catch (...) {
            LOG_APPERROR("Unkonwn exception, deal handle");
            SetError(-1, "unkonwn exception");
        }
    }

    void SetError(int code, const std::string& err_info){
        m_controller_->SetError(code, err_info);
    }
};

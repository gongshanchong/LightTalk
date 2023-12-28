#pragma once

#include "lightrpc/net/rpc/rpc_interface.h"
#include "lightrpc/common/exception.h"
#include "../proto/FriendServer.pb.h"
#include "../proto/FriendService.pb.h"
#include "../service/ZooKeeperMaster.h"
#include <cstdio>
#include <string>

#define BUFF_SIZE 256

class GetFriendListImpl : public lightrpc::RpcInterface{
public:
    GetFriendListImpl(const google::protobuf::Message* req, google::protobuf::Message* rsp, google::protobuf::RpcController* controller, ::google::protobuf::Closure* done):
    lightrpc::RpcInterface(req, rsp, controller, done){}

    void Run(){
        try {
            // 初始化请求和响应
            auto req = dynamic_cast<const ik_FriendService::FriendListRequest*>(m_req_base_);
            auto res = dynamic_cast<ik_FriendService::FriendListResponse*>(m_rsp_base_);

            //刷新zookeeper列表
            ZKMatser::getInstance()->get_follow();
            //反序列化
            ik_FriendServer::Request ser_request;
            ser_request.set_type("GetFriendList");
            ser_request.set_request(req->SerializeAsString());

            //获得一个可用的连接
            int client_fd;
            while ((client_fd = ZKMatser::getInstance()->get_service()) == -1)
            {
                ZKMatser::getInstance()->get_follow();
                sleep(1);
            }

            //发送任务信息
            string send_str = ser_request.SerializeAsString();
            if (send(client_fd, send_str.c_str(), send_str.size(), 0) == -1){
                throw "send error";
            }

            // 获取返回信息
            char recv_buf[BUFF_SIZE] = {0};
            if (recv(client_fd, recv_buf, BUFF_SIZE, 0) == -1){
                throw "recv error";
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

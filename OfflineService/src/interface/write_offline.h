#pragma once

#include "lightrpc/net/rpc/rpc_interface.h"
#include "lightrpc/common/exception.h"
#include "../proto/OfflineService.pb.h"
#include "../proto/OfflineServer.pb.h"
#include "../service/ZooKeeperMaster.h"
#include <cstdio>
#include <string>

#define BUFF_SIZE 256

class WriteOfflineImpl : public lightrpc::RpcInterface{
public:
    WriteOfflineImpl(const google::protobuf::Message* req, google::protobuf::Message* rsp, google::protobuf::RpcController* controller, ::google::protobuf::Closure* done):
    lightrpc::RpcInterface(req, rsp, controller, done){}

    void Run(){
        try {
            // 初始化请求和响应
            auto req = dynamic_cast<const ik_OfflineService::WriteOfflineRequest*>(m_req_base_);

            ZKMatser::getInstance()->get_follow();
            ik_OfflineServer::Request send_request;
            send_request.set_type("WriteOffline");
            send_request.set_request_msg(req->SerializeAsString());

            string send_str = send_request.SerializeAsString();
            //获取一个服务信息
            int client_fd;
            while ((client_fd = ZKMatser::getInstance()->get_service()) == -1)
            {
                //刷新服务列表
                ZKMatser::getInstance()->get_follow();
                sleep(1);
            }

            //发送信息
            if (send(client_fd, send_str.c_str(), send_str.size(), 0) == -1){
                throw "write-offline command send error";
            }
                
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

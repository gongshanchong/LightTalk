#pragma once

#include "lightrpc/net/rpc/rpc_interface.h"
#include "lightrpc/common/exception.h"
#include "../proto/LogService.pb.h"
#include "util.h"
#include <cstdio>
#include <string>
#include <sys/stat.h>

class LogInfoImpl : public lightrpc::RpcInterface{
public:
    LogInfoImpl(const google::protobuf::Message* req, google::protobuf::Message* rsp, google::protobuf::RpcController* controller, ::google::protobuf::Closure* done):
    lightrpc::RpcInterface(req, rsp, controller, done){}

    void Run(){
        try {
            // 初始化请求和响应
            auto req = dynamic_cast<const ik::LogRequest*>(m_req_base_);

            std::string node_name = req->name();
            std::string msg = req->msg();

            //创建目录
            std::string dir_path = "../log/";
            dir_path += node_name;
            mkdir(dir_path.c_str(), 0777);

            //写日志
            msg.insert(0, "[INFO]");
            write_file(dir_path.c_str(), msg);
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

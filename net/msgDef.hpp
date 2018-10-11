//
//  msgDef.hpp
//  testC
//
//  Created by 陈帅 on 2018/10/12.
//
#ifndef msgDef_hpp
#define msgDef_hpp

#include <cstdio>
#include <iostream>

#include "example/protobuf_rpc/msgDef.rpc.pb.h"
#include "server/pebble_server.h"
#include "clientMgr.hpp"

// Calculator服务接口的实现
class msgDef : public ::example::msgDefServerInterface {
public:
    pebble::PebbleServer* _server;
    clientMgr* cm;
    msgDef() : _server(NULL) {
        cm = clientMgr::getSingleMgr();
    }
    virtual ~msgDef() {}

    virtual void login(const ::example::LoginInfo& loginInfo,
        cxx::function<void(int32_t ret_code, const ::example::LoginRet& loginRet)>& rsp)
    {
        int32_t roleID = loginInfo.roleID();
        int32_t roomID = loginInfo.roomID();

        // 处理请求时记录请求的来源，用于反向RPC调用，不过注意这个handle是可能失效的
        int64_t g_last_handle = _server->GetLastMessageInfo()->_remote_handle;
        int32_t status = cm.roleLogin(roleID, roomID, g_last_handle);

        std::cout << "receive rpc loginInfo: " << roleID << " + " << roomID << " = " << status << std::endl;
        ::example::LoginRet loginRet;
        loginRet.set_status(status);
        rsp(pebble::kRPC_SUCCESS, loginRet);
    }

    virtual void add(const ::example::CalRequest& request,
        cxx::function<void(int32_t ret_code, const ::example::CalResponse& response)>& rsp)
    {
        int32_t a = request.a();
        int32_t b = request.b();
        int32_t c = a + b;
        std::cout << "receive rpc request: " << a << " + " << b << " = " << c << std::endl;
        ::example::CalResponse response;
        response.set_c(c);
        rsp(pebble::kRPC_SUCCESS, response);
    }
};
#endif
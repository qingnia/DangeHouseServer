
gen_rule(
    name = 'gen_rpcMsg_message',
    srcs = [
        'net/rpcMsg.proto',
    ],
    cmd = '$BUILD_DIR/../thirdparty/protobuf/bin/protoc --cpp_out=$BUILD_DIR/ $SRCS',
    deps = [
    ],
    outs = [
        'net/rpcMsg.pb.cc',
        'net/rpcMsg.pb.h',
    ],
)

gen_rule(
    name = 'gen_rpcMsg_rpc',
    srcs = [
        'net/rpcMsg.proto',
    ],
    cmd = '$BUILD_DIR/../thirdparty/protobuf/bin/protoc --plugin=protoc-gen-rpc=$BUILD_DIR/tools/compiler/pb/protobuf_rpc --rpc_out=$BUILD_DIR/ $SRCS',
    deps = [
        '//tools/compiler/pb:protobuf_rpc',
    ],
    outs = [
        'net/rpcMsg.rpc.pb.cc',
        'net/rpcMsg.rpc.pb.h',
        'net/rpcMsg.rpc.pb.inh',
    ],
)

cc_library(
    name = 'rpcMsg',
    srcs = [
        'net/rpcMsg.pb.cc',
        'net/rpcMsg.rpc.pb.cc',
    ],
    incs = [
        '../../thirdparty/protobuf/include/',
    ],
    deps = [
        ':gen_rpcMsg_message',
        ':gen_rpcMsg_rpc',
        '//src/framework/:pebble_framework',
    ]
)

cc_binary(
    name = 'singleServer',
    srcs = [
        'net/singleServer.cpp', 
    ],
    incs = [
        '../../thirdparty/protobuf/include/',
    ],
    deps = [
        ':rpcMsg',
        '//src/server/:pebble_server',
    ],
)


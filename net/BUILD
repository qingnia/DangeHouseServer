
gen_rule(
    name = 'gen_rpcMsg_message',
    srcs = [
        'rpcMsg.proto',
    ],
    cmd = '$BUILD_DIR/../thirdparty/protobuf/bin/protoc --cpp_out=$BUILD_DIR/ $SRCS',
    deps = [
    ],
    outs = [
        'rpcMsg.pb.cc',
        'rpcMsg.pb.h',
    ],
)

gen_rule(
    name = 'gen_rpcMsg_rpc',
    srcs = [
        'rpcMsg.proto',
    ],
    cmd = '$BUILD_DIR/../thirdparty/protobuf/bin/protoc --plugin=protoc-gen-rpc=$BUILD_DIR/tools/compiler/pb/protobuf_rpc --rpc_out=$BUILD_DIR/ $SRCS',
    deps = [
        '//tools/compiler/pb:protobuf_rpc',
    ],
    outs = [
        'rpcMsg.rpc.pb.cc',
        'rpcMsg.rpc.pb.h',
        'rpcMsg.rpc.pb.inh',
    ],
)

cc_library(
    name = 'rpcMsg',
    srcs = [
        'rpcMsg.pb.cc',
        'rpcMsg.rpc.pb.cc',
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
    name = 'client',
    srcs = [
        'client.cpp', 
    ],
    incs = [
        '../../thirdparty/protobuf/include/',
    ],
    deps = [
        ':rpcMsg',
        '//src/client/:pebble_client',
    ],
)
cc_binary(
    name = 'server',
    srcs = [
        'server.cpp', 
    ],
    incs = [
        '../../thirdparty/protobuf/include/',
    ],
    deps = [
        ':msgDef',
        '//src/server/:pebble_server',
    ],
)


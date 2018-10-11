
gen_rule(
    name = 'gen_msgDef_message',
    srcs = [
        'msgDef.proto',
    ],
    cmd = '$BUILD_DIR/../thirdparty/protobuf/bin/protoc --cpp_out=$BUILD_DIR/ $SRCS',
    deps = [
    ],
    outs = [
        'msgDef.pb.cc',
        'msgDef.pb.h',
    ],
)

gen_rule(
    name = 'gen_msgDef_rpc',
    srcs = [
        'msgDef.proto',
    ],
    cmd = '$BUILD_DIR/../thirdparty/protobuf/bin/protoc --plugin=protoc-gen-rpc=$BUILD_DIR/tools/compiler/pb/protobuf_rpc --rpc_out=$BUILD_DIR/ $SRCS',
    deps = [
        '//tools/compiler/pb:protobuf_rpc',
    ],
    outs = [
        'msgDef.rpc.pb.cc',
        'msgDef.rpc.pb.h',
        'msgDef.rpc.pb.inh',
    ],
)

cc_library(
    name = 'msgDef',
    srcs = [
        'msgDef.pb.cc',
        'msgDef.rpc.pb.cc',
    ],
    incs = [
        '../../thirdparty/protobuf/include/',
    ],
    deps = [
        ':gen_msgDef_message',
        ':gen_msgDef_rpc',
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
        ':msgDef',
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


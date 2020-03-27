..\..\vcpkg\installed\x64-windows\tools\protobuf\protoc.exe --cpp_out=. Tweet.proto
..\..\vcpkg\installed\x64-windows\tools\protobuf\protoc.exe --proto_path=. --grpc_out=. --plugin=protoc-gen-grpc=..\..\vcpkg\installed\x64-windows\tools\grpc\grpc_cpp_plugin.exe Tweet.proto
pause
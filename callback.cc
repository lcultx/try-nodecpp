
#include <node.h>
#include <v8.h>
using namespace v8;

Handle<Value> RunCallback(const Arguments& args){
  HandleScope scope;

  //构造cb argc argv对象
  Local<Function> cb = Local<Function>::Cast(args[0]);
  const unsigned argc = 1;
  Local<Value> argv[argc] = {Local<Value>::New(String::New("hello world"))};

  /*
  上面一句等同于：
  Local<Value> argv[argc];
  argv[0] = Local<Value>::New(String::New("hello world"));
  */

  //调用cb，参数传入global argc argv
  cb->Call(Context::GetCurrent()->Global(),argc,argv);

  return scope.Close(Undefined());
}


void Init(Handle<Object> exports,Handle<Object> module){
  module->Set(String::NewSymbol("exports"),
    FunctionTemplate::New(RunCallback)->GetFunction());
}

NODE_MODULE(callback,Init);

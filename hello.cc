#include <node.h>
#include <v8.h>

using namespace v8;
Handle<Value> Method(const Arguments& args){
  HandleScope scope;
  return scope.Close(String::New("hello,world"));
}

void init(Handle<Object> target){
  NODE_SET_METHOD(target,"hello",Method);
}

/*
void init(Handle<Object> exports){
  exports->Set(String::NewSymbol("hello"),
  FunctionTemplate::New(Method)->GetFunction());
}
*/

NODE_MODULE(hello,init);

#include "nodeutil.h"

using namespace v8;

static Handle<Value> fi_inspect(const Arguments& args) {
    HandleScope scope;
    ARG_FUNC(0, func);

    Handle<Object> retval = Object::New();
    Handle<Value> resourceName = func->GetScriptOrigin().ResourceName();
    if (*resourceName) {
        retval->Set(String::New("File"), func->GetScriptOrigin().ResourceName());
    } else {
        retval->Set(String::New("File"), Undefined());
    }
    retval->Set(String::New("Name"), func->GetName());
    retval->Set(String::New("InferredName"), func->GetInferredName());
    retval->Set(String::New("LineNumber"), Integer::New(func->GetScriptLineNumber()));
    retval->Set(String::New("ColumnNumber"), Integer::New(func->GetScriptColumnNumber()));
    return scope.Close(retval);
}

extern "C" void init(Handle<Object> target) {
    NODE_SET_METHOD(target, "inspect", fi_inspect);
}


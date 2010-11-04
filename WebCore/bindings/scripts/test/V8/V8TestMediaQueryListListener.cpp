/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#include "config.h"
#include "V8TestMediaQueryListListener.h"

#include "ExceptionCode.h"
#include "RuntimeEnabledFeatures.h"
#include "V8Binding.h"
#include "V8BindingMacros.h"
#include "V8BindingState.h"
#include "V8DOMWrapper.h"
#include "V8IsolatedContext.h"
#include "V8MediaQueryListListener.h"
#include "V8Proxy.h"

namespace WebCore {

WrapperTypeInfo V8TestMediaQueryListListener::info = { V8TestMediaQueryListListener::GetTemplate, V8TestMediaQueryListListener::derefObject, 0 };

namespace TestMediaQueryListListenerInternal {

template <typename T> void V8_USE(T) { }

static v8::Handle<v8::Value> methodCallback(const v8::Arguments& args)
{
    INC_STATS("DOM.TestMediaQueryListListener.method");
    TestMediaQueryListListener* imp = V8TestMediaQueryListListener::toNative(args.Holder());
    EXCEPTION_BLOCK(MediaQueryListListener*, listener, V8MediaQueryListListener::HasInstance(args[0]) ? V8MediaQueryListListener::toNative(v8::Handle<v8::Object>::Cast(args[0])) : 0);
    imp->method(listener);
    return v8::Handle<v8::Value>();
}

} // namespace TestMediaQueryListListenerInternal

static v8::Persistent<v8::FunctionTemplate> ConfigureV8TestMediaQueryListListenerTemplate(v8::Persistent<v8::FunctionTemplate> desc)
{
    v8::Local<v8::Signature> defaultSignature = configureTemplate(desc, "TestMediaQueryListListener", v8::Persistent<v8::FunctionTemplate>(), V8TestMediaQueryListListener::internalFieldCount,
        0, 0,
        0, 0);
    v8::Local<v8::ObjectTemplate> instance = desc->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> proto = desc->PrototypeTemplate();
    

    // Custom Signature 'method'
    const int methodArgc = 1;
    v8::Handle<v8::FunctionTemplate> methodArgv[methodArgc] = { V8MediaQueryListListener::GetRawTemplate() };
    v8::Handle<v8::Signature> methodSignature = v8::Signature::New(desc, methodArgc, methodArgv);
    proto->Set(v8::String::New("method"), v8::FunctionTemplate::New(TestMediaQueryListListenerInternal::methodCallback, v8::Handle<v8::Value>(), methodSignature));

    // Custom toString template
    desc->Set(getToStringName(), getToStringTemplate());
    return desc;
}

v8::Persistent<v8::FunctionTemplate> V8TestMediaQueryListListener::GetRawTemplate()
{
    static v8::Persistent<v8::FunctionTemplate> V8TestMediaQueryListListenerRawCache = createRawTemplate();
    return V8TestMediaQueryListListenerRawCache;
}

v8::Persistent<v8::FunctionTemplate> V8TestMediaQueryListListener::GetTemplate()
{
    static v8::Persistent<v8::FunctionTemplate> V8TestMediaQueryListListenerCache = ConfigureV8TestMediaQueryListListenerTemplate(GetRawTemplate());
    return V8TestMediaQueryListListenerCache;
}

bool V8TestMediaQueryListListener::HasInstance(v8::Handle<v8::Value> value)
{
    return GetRawTemplate()->HasInstance(value);
}


v8::Handle<v8::Object> V8TestMediaQueryListListener::wrapSlow(TestMediaQueryListListener* impl)
{
    v8::Handle<v8::Object> wrapper;
    V8Proxy* proxy = 0;
    wrapper = V8DOMWrapper::instantiateV8Object(proxy, &info, impl);
    if (wrapper.IsEmpty())
        return wrapper;

    impl->ref();
    getDOMObjectMap().set(impl, v8::Persistent<v8::Object>::New(wrapper));
    return wrapper;
}

void V8TestMediaQueryListListener::derefObject(void* object)
{
    static_cast<TestMediaQueryListListener*>(object)->deref();
}

} // namespace WebCore

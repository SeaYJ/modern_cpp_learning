#pragma once

#include <iostream>

/************************\
* 内联命名空间的定义和使用 *
\************************/

/**
 * inline namespace Child {} 中的元素会被导入到 namespace Parent 中。
 * 
 * 值得注意的是，inline 关键字不可以作用于顶层命名空间，也就是下例中的 namespace Parent。
 */
namespace Parent {
    namespace Child_0 {
        void func() { std::cout << "Parent::Child_0::func()" << std::endl; }
    }

    inline namespace Child_1 {
        void func() { std::cout << "Parent::Child_1::func()" << std::endl; }
    }
}

void test_inline_namespace() {
    Parent::Child_0::func();    // 打印：Parent::Child_0::func()
    Parent::Child_1::func();    // 打印：Parent::Child_1::func()
    Parent::func();             // 打印：Parent::Child_1::func()，因为 inline 关键字将 namespace Child_1 中的元素导入到了 namespace Parent 中
}

/**
 * 应用场景：库函数的升级
 * 库函数作者可以通过改变 inline 作用的位置实现保留旧函数的前提下升级函数。
 */
namespace FunctionLibrary {
    // 原来作用于 namespace Version_1_0，那么原来使用的就是 V1.0 的 foo() 
    namespace Version_1_0 {
        void foo() { std::cout << "V1.0 of foo()" << std::endl; }
    }

    // 现在作用于 namespace Version_2_0，那么现在使用的就是 V2.0 的 foo()
    inline namespace Version_2_0 {
        void foo() { std::cout << "V2.0 of foo()" << std::endl; }
    }
}

void apply_inline_namespace() {
    // 如果用户想继续使用 V1.0 的 foo() 就需要指定 Version_1_0 命名空间
    FunctionLibrary::Version_1_0::foo();    // 打印：V1.0 of foo()

    // 此时 foo() 被升级为 V2.0 的实现，随着库升级。
    FunctionLibrary::foo(); // 打印：V2.0 of foo()
}


/*************\
* 嵌套命名空间 *
\*************/

namespace A {
    namespace B {
        namespace C {
            void foo() {}
        }
    }
}
// 在 C++11 之后可以等价于下面的写法（嵌套命名空间的简化）
namespace A::B::C {
    void foo() {}
}

namespace A {
    inline namespace B {
        namespace C {
            void foo() {}
        }
    }
}
// 在 C++20 之后“才支持”内联嵌套命名空间的简化，所以上述代码等价于下面的写法（内联嵌套命名空间的简化）
namespace A::inline B::C {
    void foo() {}
}
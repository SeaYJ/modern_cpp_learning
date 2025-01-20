#pragma once

#include <iostream>

/************************\
* ���������ռ�Ķ����ʹ�� *
\************************/

/**
 * inline namespace Child {} �е�Ԫ�ػᱻ���뵽 namespace Parent �С�
 * 
 * ֵ��ע����ǣ�inline �ؼ��ֲ����������ڶ��������ռ䣬Ҳ���������е� namespace Parent��
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
    Parent::Child_0::func();    // ��ӡ��Parent::Child_0::func()
    Parent::Child_1::func();    // ��ӡ��Parent::Child_1::func()
    Parent::func();             // ��ӡ��Parent::Child_1::func()����Ϊ inline �ؼ��ֽ� namespace Child_1 �е�Ԫ�ص��뵽�� namespace Parent ��
}

/**
 * Ӧ�ó������⺯��������
 * �⺯�����߿���ͨ���ı� inline ���õ�λ��ʵ�ֱ����ɺ�����ǰ��������������
 */
namespace FunctionLibrary {
    // ԭ�������� namespace Version_1_0����ôԭ��ʹ�õľ��� V1.0 �� foo() 
    namespace Version_1_0 {
        void foo() { std::cout << "V1.0 of foo()" << std::endl; }
    }

    // ���������� namespace Version_2_0����ô����ʹ�õľ��� V2.0 �� foo()
    inline namespace Version_2_0 {
        void foo() { std::cout << "V2.0 of foo()" << std::endl; }
    }
}

void apply_inline_namespace() {
    // ����û������ʹ�� V1.0 �� foo() ����Ҫָ�� Version_1_0 �����ռ�
    FunctionLibrary::Version_1_0::foo();    // ��ӡ��V1.0 of foo()

    // ��ʱ foo() ������Ϊ V2.0 ��ʵ�֣����ſ�������
    FunctionLibrary::foo(); // ��ӡ��V2.0 of foo()
}


/*************\
* Ƕ�������ռ� *
\*************/

namespace A {
    namespace B {
        namespace C {
            void foo() {}
        }
    }
}
// �� C++11 ֮����Եȼ��������д����Ƕ�������ռ�ļ򻯣�
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
// �� C++20 ֮�󡰲�֧�֡�����Ƕ�������ռ�ļ򻯣�������������ȼ��������д��������Ƕ�������ռ�ļ򻯣�
namespace A::inline B::C {
    void foo() {}
}
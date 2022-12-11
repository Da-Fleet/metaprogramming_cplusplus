using namespace std;

template <typename Action, int Begin, int End, int Step = 1>
struct UnrollerS {
    static void step() {
        Action::action(Begin);
        UnrollerS<Action, Begin+Step, End, Step>::step();
    }
};
//end of static unroller
template <typename Action, int End, int Step>
struct UnrollerS<Action, End, End, Step> {
    static void step() { }
};

//dynamic unroller
template <typename Action, int Begin, int End, int Step = 1>
struct UnrollerD {
    static void step(Action& a) {
        a.action(Begin);
        UnrollerD<Action, Begin+Step, End>::step(a);
    }
};
//end of dynamic unroller
template <typename Action, int End, int Step>
struct UnrollerD<Action, End, End, Step> {
    static void step(Action& a) { }
};

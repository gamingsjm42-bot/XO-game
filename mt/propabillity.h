//includes
#include "feild.h"
#include <random>
#include <functional>
//
namespace mt
{
    /// @brief that function ret
    /// @tparam T 
    template<typename T>
    class RandomExperiment
    {
        protected:
        //that functop
        virtual void getElement(int numberRandom);
        //
        std::function<int()> rnd;
        public:
        //
        std::vector<T> get(){return getElement(rnd());}
        //
        void setRandomFun(std::function<int()> rndFn){rnd = rndFn;}
    };
    ///
    class 
} // namespace mt

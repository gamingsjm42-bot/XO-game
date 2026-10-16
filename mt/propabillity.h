//includes
#include "field.h"
#include <map>
#include <random>
#include <functional>
//
namespace mt
{
    //

    /// @brief that function ret
    /// @tparam T 
    template<typename element>
    class RandomExperiment
    {
        protected:
        /// @brief that function return
        /// @param numberRandom 
        virtual std::vector<element> getElement(int numberRandom);
        ///that random by user
        std::function<int()> rnd= [](){return rand();};
        public:
        /// @brief that 
        /// @return 
        std::vector<element> get(){return getElement(rnd());}
        /// @brief that 
        /// @param rndFn 
        void setRandomFun(std::function<int()> rndFn){rnd = rndFn;}
    };
    ///
    template <typename element>
    class DrawingExperiment : RandomExperiment<element>
    {
        //
        protected:
        /// @brief that number of element returning
        size_t numberOfReturningElement;
        //that 
        field<element> elements; 
        public:
        DrawingExperiment(size_t numberOfReturningElement ,field<element> elements)
        {
            //set variables
            this->numberOfReturningElement = numberOfReturningElement;
            this->elements = elements;
            //set a 0=<Xi<=card(lambda)
            setRandomFun([this](){return rand()%(this->elements.card());});
        } 
    };
    //
    template<typename element>
    class LiniarExperiment:public DrawingExperiment <element>
    {
        
        std::vector<element> getElement(int numberRandom)
        {
            ///
            std::vector<element> returning;
            ///
            returning.push_back(this->elements.getElement(numberRandom));
            ///
            return returning;
        }
    };
    
} // namespace mt

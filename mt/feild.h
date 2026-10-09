//fix include
//include
#include <vector>
//n
namespace mt
{
    //
    template<typename element>
    class thiory
    {
        
        bool is_correct;
        //
        public:
        //
        operator bool (){return is_correct;}
        thiory (thiory<element> __l):is_correct(__l){}
         thiory<element> operator^(thiory<element> auther){return *this&&auther;}
         //
         thiory<element> operator&(thiory<element> auther){return *this|| auther;}
         //
         thiory<element> implication(thiory<element> auther){return non(*this)&auther;}
         //
         thiory<element> operator==(thiory<element> auther){return bool(*this)==bool(auther);}
         //
         thiory<element> equivalent(thiory<element> auther){return  *this==auther;}

    };
    //
    template<typename element>
    thiory<element> non(thiory<element> t){return thiory<element>(!bool(t));}
    /// @brief 
    /// @tparam number 
    template<typename element >
    class feild
    {
        //
        private:
        std::vector<element> elements ;
        public:
        /// @brief 
        /// @param elements 
        feild(std::vector<element> elements){this->elements = elements;}
        //
        thiory<element> E(element _e){for(auto elemnt = elements.begin();elemnt!=elements.end();elemnt++){if(*elemnt==_e) return 1;return 0;}}
        //
        /*feild<element> U(feild<element> _e)
        {
            //
            std::vector<element> returning;
            //
            for (auto self = elements.begin(); self != elements.end(); self++) returning.push_back(self);
            
        }*/
       element getElement(size_t id){return elements[id];}
    };
} // namespace mt

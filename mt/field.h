//fix include
//include
#include <vector>
//n
namespace mt
{
    //
    template<typename element>
    class theory
    {
        
        bool is_correct;
        //
        public:
        //
        operator bool (){return is_correct;}
        theory <element> (bool __l):is_correct(__l){}
         theory<element> operator^(theory<element> auther){return *this&&auther;}
         //
         theory<element> operator&(theory<element> auther){return *this|| auther;}
         //
         theory<element> implication(theory<element> auther){return non(*this)&auther;}
         //
         theory<element> operator==(theory<element> auther){return bool(*this)==bool(auther);}
         //
         theory<element> equivalent(theory<element> auther){return  *this==auther;}

    };
    //
    template<typename element>
    theory<element> non(theory<element> t){return theory<element>(!bool(t));}
    /// @brief 
    /// @tparam number 
    template<typename element >
    class field
    {
        //
        private:
        std::vector<element> elements ;
        public:
        /// @brief 
        /// @param elements 
        field(std::vector<element> elements){this->elements = elements;}
        //
        theory<element> E(element _e){for(auto elemnt = elements.begin();elemnt!=elements.end();elemnt++){if(*elemnt==_e) return 1;return 0;}}
        //
        /*field<element> U(field<element> _e)
        {
            //
            std::vector<element> returning;
            //
            for (auto self = elements.begin(); self != elements.end(); self++) returning.push_back(self);
            
        }*/
       element getElement(size_t id){return elements[id];}
       // 
       size_t card(){return elements.size();}
       //
    };
    //
    
} // namespace mt


#pragma once

#include <type_traits>  //  std::enable_if, std::is_base_of, std::is_member_pointer
#include <sstream>  //  std::stringstream

namespace sqlite_orm {
    
    /**
     *  This is base class for every class which is used as a custom table alias.
     *  For more information please look through self_join.cpp example
     */
    struct alias_tag {};
    
    /**
     *  This is a common built-in class used for custom single character table aliases.
     *  Also you can use language aliases `alias_a`, `alias_b` etc. instead
     */
    template<class T, char A>
    struct alias : alias_tag {
        using type = T;
        
        static char get() {
            return A;
        }
    };
    
    namespace internal {
        
        template<class T, class C>
        struct alias_column_t {
            using alias_type = T;
            using column_type = C;
            
            column_type column;
            
            alias_column_t() {};
            
            alias_column_t(column_type column_): column(column_) {}
        };
        
        template<class T, class SFINAE = void>
        struct alias_extractor;
        
        template<class T>
        struct alias_extractor<T, typename std::enable_if<std::is_base_of<alias_tag, T>::value>::type> {
            static std::string get() {
                std::stringstream ss;
                ss << T::get();
                return ss.str();
            }
        };
        
        template<class T>
        struct alias_extractor<T, typename std::enable_if<!std::is_base_of<alias_tag, T>::value>::type> {
            static std::string get() {
                return {};
            }
        };
    }
    
    /**
     *  @return column with table alias attached. Place it instead of a column statement in case you need to specify a
     *  column with table alias prefix like 'a.column'. For more information please look through self_join.cpp example
     */
    template<class T, class C>
    internal::alias_column_t<T, C> alias_column(C c) {
        static_assert(std::is_member_pointer<C>::value, "alias_column argument must be a member pointer mapped to a storage");
        return {c};
    }
    
    template<class T> using alias_a = alias<T, 'a'>;
    template<class T> using alias_b = alias<T, 'b'>;
    template<class T> using alias_c = alias<T, 'c'>;
    template<class T> using alias_d = alias<T, 'd'>;
    template<class T> using alias_e = alias<T, 'e'>;
    template<class T> using alias_f = alias<T, 'f'>;
    template<class T> using alias_g = alias<T, 'g'>;
    template<class T> using alias_h = alias<T, 'h'>;
    template<class T> using alias_i = alias<T, 'i'>;
    template<class T> using alias_j = alias<T, 'j'>;
    template<class T> using alias_k = alias<T, 'k'>;
    template<class T> using alias_l = alias<T, 'l'>;
    template<class T> using alias_m = alias<T, 'm'>;
    template<class T> using alias_n = alias<T, 'n'>;
    template<class T> using alias_o = alias<T, 'o'>;
    template<class T> using alias_p = alias<T, 'p'>;
    template<class T> using alias_q = alias<T, 'q'>;
    template<class T> using alias_r = alias<T, 'r'>;
    template<class T> using alias_s = alias<T, 's'>;
    template<class T> using alias_t = alias<T, 't'>;
    template<class T> using alias_u = alias<T, 'u'>;
    template<class T> using alias_v = alias<T, 'v'>;
    template<class T> using alias_w = alias<T, 'w'>;
    template<class T> using alias_x = alias<T, 'x'>;
    template<class T> using alias_y = alias<T, 'y'>;
    template<class T> using alias_z = alias<T, 'z'>;
}

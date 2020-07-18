#ifndef LOG_H_
#define LOG_H_

#define error_msg(str) do { std::cout << str << std::endl; } while( false )
#define info_msg(str) do { std::cout << str << std::endl; } while( false )

#ifdef DEBUG
#define debug_msg(str) do { std::cout << str << std::endl; } while( false )
#else
#define debug_msg(str) do { } while ( false )
#endif

#endif

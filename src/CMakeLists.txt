set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_RELEASE "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D __FILENAME__='\"$(subst  ${CMAKE_SOURCE_DIR}/,,$(abspath $<))\"'")
#CXX_FLAGS+=-D__FILENAME__='\"$(subst $(SOURCE_PREFIX)/,,$(abspath $<))\"'"

set(SOURCES main.cpp
            Instance.cpp
            Satelite.cpp
            Satelite.h
        Auxiliary.cpp
            Auxiliary.h
            LocalSearch.cpp
            LocalSearch.h
            Route.cpp
            Vnd.cpp
            Vnd.h
            ViabilizadorRotaEv.cpp
            ViabilizadorRotaEv.h
            Teste.cpp
            Teste.h
            Solution.cpp
            EvRoute.cpp
        greedyAlgorithm.cpp
            greedyAlgorithm.h
            mersenne-twister.h
            mersenne-twister.cpp
            Constants.h
            Constants.cpp


        )
add_executable(run ${SOURCES})

#target_link_libraries(use_boost ${Boost_LIBRARIES})
target_link_libraries(run LINK_PUBLIC ${Boost_LIBRARIES})

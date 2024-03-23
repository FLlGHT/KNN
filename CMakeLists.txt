cmake_minimum_required(VERSION 3.27)
project(ForMula)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        ForMula main.cpp
        knn/parser/interactions_parser.h
        knn/parser/interactions_parser.cpp
        knn/parser/platform_summary.h
        knn/parser/platform_summary.cpp
        knn/matrix/matrix_utils.cpp
        knn/parser/artists_parser.h
        knn/parser/artists_parser.cpp
        knn/parser/string_utils.h
        knn/parser/string_utils.cpp
        knn/collections/collections_utils.h
        knn/collections/collections_utils.cpp
        knn/collections/element.h
        knn/collections/element.cpp
        knn/parser/artists_summary.h
        knn/parser/artists_summary.cpp
        knn/algorithm/knn.h
        knn/algorithm/knn.cpp
        knn/interface/knn_engine.h
        knn/interface/knn_engine.cpp
)

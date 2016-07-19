cmake_minimum_required(VERSION 2.8)
add_definitions("-std=c++11")
add_library(DataStructures STATIC
  card.cpp
  DCard.cpp
  hand.cpp
)
package com.myron.ndklearn

data class Person(
    val name: String = "",
    val age: Int = 0
) {
    override fun toString(): String {
        return "$name,$age"
    }
}
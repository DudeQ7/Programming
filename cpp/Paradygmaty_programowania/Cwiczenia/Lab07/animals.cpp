#include <iostream>
class Animal
{
private:
    /* data */
public:
    void makeSound()
    {
        std::cout << "Animal makes a sound" << std::endl;
    }
};
class Dog:public Animal
{
public:
    void makeSound()
    {
        std::cout << "Dog barks" << std::endl;
    }
};
class cat:public Animal
{
public:
    void makeSound()
    {
        std::cout << "Cat meows" << std::endl;
    }
};
void funkcja(Animal& anim)
{
    anim.makeSound();
}
int main()
{
    Dog d;
    cat c;
    funkcja(d);
    funkcja(c);
    return 0;
}
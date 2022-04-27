#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

void printCollectionElements(const Collection &collection) {
    for (const auto &it: collection)
        if (it)
            it->print();
}

void printAreas(const Collection &collection) {
    for (const auto &it: collection)
        if (it)
            cout << it->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection &collection,
                                     std::function<bool(shared_ptr<Shape>)> predicate,
                                     const std::string& info) {
    auto iter = std::find_if(collection.begin(), collection.end(), std::move(predicate));
    if (*iter != nullptr) {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    } else {
        cout << "There is no shape matching predicate " << info << endl;
    }
}


constexpr unsigned int fib(const unsigned int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    constexpr unsigned int fibFor45 = fib(20); // 45 was too complex for my computer to handle and IDE returned errors

    std::cout << "Fibonacci for 45: " << fibFor45 << std::endl;

    Collection shapes = {
            make_shared<Circle>(2.0),
            make_shared<Circle>(3.0),
            nullptr,
            make_shared<Circle>(4.0),
            make_shared<Rectangle>(10.0, 5.0),
            make_shared<Square>(3.0),
            make_shared<Circle>(4.0),
            make_shared<Rectangle>(Color::RED),
            make_shared<Circle>(Color::GREEN),
            make_shared<Square>(Color::BLUE)
    };
    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), [](const shared_ptr<Shape> &s1, const shared_ptr<Shape> &s2) {
        if (s1 == nullptr)
            return true;
        if (s2 == nullptr)
            return false;
        return s1->getArea() < s2->getArea();
    });

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, [](const shared_ptr<Shape> &s) {
        if (s) {
            return s->getArea() > 20.0;
        } else {
            return false;
        }
    }, "Area > 20");
    findFirstShapeMatchingPredicate(shapes, [x = 10](const shared_ptr<Shape> &s) {
        if (s) {
            return s->getArea() < x;
        } else {
            return false;
        }
    }, "Area < 10");

    return 0;
}


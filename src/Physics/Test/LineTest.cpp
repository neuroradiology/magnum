/*
    Copyright © 2010, 2011, 2012 Vladimír Vondruš <mosra@centrum.cz>

    This file is part of Magnum.

    Magnum is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License version 3
    only, as published by the Free Software Foundation.

    Magnum is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU Lesser General Public License version 3 for more details.
*/

#include <TestSuite/Tester.h>

#include "Math/Constants.h"
#include "Math/Matrix4.h"
#include "Physics/Line.h"

namespace Magnum { namespace Physics { namespace Test {

class LineTest: public Corrade::TestSuite::Tester {
    public:
        LineTest();

        void applyTransformation();
};

LineTest::LineTest() {
    addTests(&LineTest::applyTransformation);
}

void LineTest::applyTransformation() {
    Physics::Line3D line({1.0f, 2.0f, 3.0f}, {-1.0f, -2.0f, -3.0f});
    line.applyTransformationMatrix(Matrix4::rotation(Deg(90.0f), Vector3::zAxis()));
    CORRADE_COMPARE(line.transformedA(), Vector3(-2.0f, 1.0f, 3.0f));
    CORRADE_COMPARE(line.transformedB(), Vector3(2.0f, -1.0f, -3.0f));
}

}}}

CORRADE_TEST_MAIN(Magnum::Physics::Test::LineTest)

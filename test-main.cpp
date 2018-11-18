//
// Created by marsofandrew on 18.11.18.
//

#define BOOST_TEST_MODULE main_module

#include <boost/test/included/unit_test.hpp>

#include "code/GeneratorImpl.hpp"
#include "library/include/SimpleTimer.hpp"

BOOST_AUTO_TEST_SUITE(GeneratorImplTests)

  BOOST_AUTO_TEST_CASE(FirstTest){
    std::shared_ptr<Generator> generator = std::make_shared<GeneratorImpl>(GeneratorImpl(0,1,2));
    std::shared_ptr<Timer> timer = std::make_shared<SimpleTimer>();
    generator->setTimer(timer);
    generator->createNewOrder();
    BOOST_CHECK(generator->getTimeToNextEvent()>=1);
  }

  BOOST_AUTO_TEST_CASE(SecondTest){
    std::shared_ptr<Generator> generator = std::make_shared<GeneratorImpl>(GeneratorImpl(0,1,2));
    std::shared_ptr<Timer> timer = std::make_shared<SimpleTimer>();
    generator->setTimer(timer);
    generator->createNewOrder();
    BOOST_CHECK_EQUAL(generator->getAmountOfGeneratedOrders(), 1);
    BOOST_CHECK(generator->getTimeToNextEvent()>=1);

    timer->add(generator->getTimeToNextEvent());
    BOOST_CHECK(Timer::equals(generator->getTimeToNextEvent(), 0));

    auto order = generator->getOrder();
    BOOST_CHECK(order!= nullptr);
  }

BOOST_AUTO_TEST_SUITE_END()


//
// Created by ilyab on 12.10.2022.
//

#include "EventChainLink.h"

namespace events {

    EventChainLink *EventChainLink::addNext(EventChainLink *next, bool delete_previous) {
        if (delete_previous && next_chain_link_ != nullptr) {
            delete next_chain_link_;
        } else if (next_chain_link_ != nullptr) {
            next_chain_link_->setPrevious(next);
            next->addNext(next_chain_link_);
        }
        next->setPrevious(this);
        next_chain_link_ = next;
        return next_chain_link_;
    }

    void EventChainLink::dispatchNext(Point point) {
        if (next_chain_link_ != nullptr) {
        // if (next_chain_link_ != nullptr && transmit_checker_()) {
            next_chain_link_->dispatch(point);
        }
    }

    EventChainLink::~EventChainLink() {
        delete next_chain_link_;
    }

    EventChainLink *EventChainLink::getFirst() {
        if (prev_chain_link_ == nullptr) {
            return this;
        }
        return prev_chain_link_->getFirst();
    }

    void EventChainLink::setPrevious(EventChainLink *previous) {
        prev_chain_link_ = previous;
    }

    EventChainLink *EventChainLink::setTransmitChecker(std::function<bool()> transmit_checker) {
        transmit_checker_ = std::move(transmit_checker);
        return this;
    }

    EventChainLink *EventChainLink::addToEnd(EventChainLink *event) {
        if (next_chain_link_) {
            return next_chain_link_->addToEnd(event);
        } else {
            return addNext(event);
        }
    }


}
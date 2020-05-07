//
// Created by Nicholas Hillier on 2020-04-26.
//
#pragma once
#ifndef C_PLUS_PLUS_PLAYGROUND_STATUS_H
#define C_PLUS_PLUS_PLAYGROUND_STATUS_H

enum Status {
    Pending,
    Approved,
    Cancelled
};

enum class FileError {
    notfound,
    ok
};

enum class NetworkError {
    disconnected,
    ok
};

#endif //C_PLUS_PLUS_PLAYGROUND_STATUS_H

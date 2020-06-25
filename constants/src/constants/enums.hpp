#ifndef CONSTANTS_ENUMS_H
#define CONSTANTS_ENUMS_H

enum ElementType {
    INT = 0,
    LONG = 1,
    UINT = 2,
    UNINT64 = 3,
    STRING = 4,
    BUFFER = 5,
    BUFFER_ARRAY = 6
};

enum NodeType {
    BLANK_NODE = 0,
    BRANCH_NODE = 1,
    EXTENSION_NODE = 2,
    LEAF_NODE = 3
};

enum EmbeddedNode {
    BYTE = 0,
    BYTE_ARRAY = 1
};

enum NodeSize {
    BLANK_NODE_SIZE = 0,
    BRANCH_NODE_SIZE = 17,
    OTHER_NODE_SIZE = 2
};

#endif
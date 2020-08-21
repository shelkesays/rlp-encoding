#ifndef CONSTANTS_ENUMS_H
#define CONSTANTS_ENUMS_H

// enum ElementType {
//     CHAR = 0,
//     INT = 1,
//     LONG = 2,
//     UINT = 3,
//     UNINT64 = 4,
//     STRING = 5,
//     BUFFER = 6,
//     BUFFER_ARRAY = 7
// };

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
# Hierarchical Next Hop Group

Title       | Hierarchical Next Hop Group
------------|----------------
Authors     | Mellanox
Status      | In review
Type        | Standards track
Created     | 12/13/2019
SAI-Version | 1.5

## Overview
The typical data center topology implements load balancing to the spine by creating an ECMP container, which satisfies the needs for this usecase.
When some of the next hops become unreachable, packets are rehashed to the ramainder of the next hops.

```
                    +------------------------+         +------------------------+
                    |                        |         |                        |
                    |                        |         |                        |
                    |                        |         |                        |
                    |                        |         |                        |
                    |                        |         |                        |
                    |                        |         |                        |
                    +--x---------x---x-------+         +------x---x----------x--+
                      /           \   \_____            _____/   /            \
                     /             \        \__________/        /              \
                    /               \       _____/\_____       /                \
                   /                 \_____/            \_____/                  \                     . . .
                  /             _____/\                      /\_____              \
                 /        _____/       \                    /       \_____         \
                /        /              \                  /              \         \
   +---------{-x--------x-}-+        +-{-x----------------x-}-+        +-{-x---------x-}--------+
   |                        |        |                        |        |                        |
   |                        |        |                        |        |                        |
   |                        |        |                        |        |                        |
   |                        |        |                        |        |                        |
   |                        |        |                        |        |                        |
   |                        |        |                        |        |                        |
   +----x----x----x----x----+        +----x----x----x----x----+        +----x----x----x----x----+
        |    |    |    |                  |    |    |    |                  |    |    |    |
        |    |    |    |                  |    |    |    |                  |    |    |    |
        |    |    |    |                  |    |    |    |                  |    |    |    |
```

There is, however, a place for more complicated usecases.
For instance, there might be N applicances connected to the switch, each with M next hops.
When one of the next hops is down, the failover is different - packets that were hashed to that next hop will move to a different next hop, but **_within the same appliance_**.
To achieve this kind of behavior, an Hierarchy of next hop groups is formed - first on the appliance level, then - on next hop level within the appliance.

```
   +--------------------------------------------------------------------------------------------+
   |                                                                                            |
   |                                                                                            |
   |        {--X---------------------------------X---------------------------------X--}         |
   |         / |  \                            / |  \                            / |  \         |
   |        /  |   \                          /  |   \                          /  |   \        |
   |       /   |    \                        /   |    \                        /   |    \       |
   |      |   /  \   |                      |   /  \   |                      |   /  \   |      |
   |     /   |    |   \                    /   |    |   \                    /   |    |   \     |
   +(-{-x----x----x----x-}--------------{-x----x----x----x-}--------------{-x----x----x----x-}-)+
        |    |    |    |                  |    |    |    |                  |    |    |    |
        |    |    |    |                  |    |    |    |                  |    |    |    |
        |    |    |    |                  |    |    |    |                  |    |    |    |
   +----x----x----x----x----+        +----x----x----x----x----+        +----x----x----x----x----+
   |                        |        |                        |        |                        |
   |                        |        |                        |        |                        |
   |                        |        |                        |        |                        |
   |                        |        |                        |        |                        |
   |                        |        |                        |        |                        |
   |                        |        |                        |        |                        |
   +------------------------+        +------------------------+        +------------------------+
```

## SAI next hop group member
The following attribute will be extended with a new allowed type:

    /**
     * @brief Next hop id
     *
     * @type sai_object_id_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     * @objects SAI_OBJECT_TYPE_NEXT_HOP SAI_OBJECT_TYPE_NEXT_HOP_GROUP
     */
    SAI_NEXT_HOP_GROUP_MEMBER_ATTR_NEXT_HOP_ID
    
Besides the SAI_OBJECT_TYPE_NEXT_HOP the new allowed object type is SAI_OBJECT_TYPE_NEXT_HOP_GROUP. It will allow for chaining the next hop groups into hierarchy.

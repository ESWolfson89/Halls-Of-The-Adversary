#ifndef ITEM_H_
#define ITEM_H_

#include "globals.h"
#include "point.h"

enum damage_modifier_prefix
{
    DMP_USELESS,
    DMP_FRAIL,
    DMP_WEAK,
    DMP_SOFT,
    DMP_GREAT,
    DMP_DEADLY,
    DMP_LETHAL,
    DMP_PUNISHING,
    DMP_DEVASTATING,
    DMP_ULTIMATE
};

enum accuracy_modifier_prefix
{
    AMP_DEFECTIVE,
    AMP_UNRELIABLE,
    AMP_UNWIELDY,
    AMP_INEXACT,
    AMP_ACCURATE,
    AMP_UNERRING,
    AMP_TARGETING,
    AMP_PINPOINTING,
    AMP_INEXORABLE,
    AMP_UNSTOPPABLE
};

static const uint64 itemCategoryCreateChance[NUM_ITEM_CATEGORIES] = {
    0,16,6,10,16,4,6,13,11,8
};

static const uint64 credit_worth[11] =
{
    1,2,5,10,25,100,1000,10000,100000,1000000,1000000000
};

static const int firearm_ranges[14] =
{
    -1,-1,-1,-1,9,5,5,-1,-1,1,8,-1,3,-1
};

// NOTA = none of the above
enum item_category
{
    ITEM_NIL,
    ITEM_CREDIT,
    ITEM_MELEE_WEAPON,
    ITEM_FIREARM_WEAPON,
    ITEM_AMMUNITION,
    ITEM_WEAPON_UPGRADE,
    ITEM_STATBOOSTER,
    ITEM_MEDKIT,
    ITEM_DEVICE,
    ITEM_ARMOR
};

enum item_list_category
{
    ITEMLIST_PILE,
    ITEMLIST_INV,
    ITEMLIST_SHOP
};

struct weapon_stats
{
    dice_roll dam;

    int to_hit;

    bool is_stealth;

    bool exploding;

    bool travel_through;

    uint crit_perc;

    uint crit_multiplier;

    uint stun_chance;
};

// armor can not protect against death rays at all!
struct armor_stats
{
    // defense
    int basedv_value;
    // protection
    int basepv_value;
    // bonus protections:
    // ...
    // resisting all ballistic weapons, direct launcher hit, etc...
    // resist combat knife, giant sword, diamond sword, sword, and metal rod
    int metallic_bonus;
    // resist flamethrower, pulse cannon, plasma cannon, explosion fire
    // resist laser beams, incinerate attack, launcher explosion
    int energy_bonus;
};

struct container_stats
{
    uint quant;

    uint max_quant;
};

static const weapon_stats null_weapon = {{0,0,0},0,false,false,false,0,1,0};

static const armor_stats null_armor = {0,0,0,0};

static const container_stats null_container = {0,0};

// default item statistics
struct item_stats
{
    item_t i_type; // enum type of item

    int weight;

    int frequency;

    uint default_quantity;

    uint base_cost;

    item_category category;

    weapon_stats wepstats;

    container_stats num_subitems;

    armor_stats armstats;

    int misc_val;

    bool is_artifact;

    STRING name;

    int min_level;
};

static const STRING weapon_modifier_strings[2][10] =
{
    {
     "useless",
     "frail",
     "weak",
     "soft",
     "great",
     "deadly",
     "lethal",
     "punishing",
     "devastating",
     "ultimate"
    },
    {
     "defective",
     "unreliable",
     "unwieldy",
     "inexact",
     "accurate",
     "unerring",
     "targeting",
     "pinpointing",
     "inexorable",
     "unstoppable"
    }
};

static const STRING unidentifiedDeviceNames[NUM_TOTAL_DEVICES] = {
    "cylinderical device",
    "glowing device",
    "red device",
    "green metallic device",
    "slimy device",
    "scalding device",
    "crystal device"
};

static const chtype deviceSymbols[NUM_TOTAL_DEVICES] =
{
    { {color_darkgray, color_black}, (int)'?' },
    { {color_orangeyellow, color_black}, (int)'?'},
    { {color_red, color_black}, (int)'?' },
    { {color_darkgreen, color_black}, (int)'?' },
    { {color_purple, color_black}, (int)'?' },
    { {color_orange, color_black}, (int)'?' },
    { {color_cyan, color_black}, (int)'?'}
};

static const item_stats item_default_stats[NUM_TOTAL_ITEMS] =
{
    {
        NIL_i, 0, 0, 0, 0,
        ITEM_NIL, null_weapon, null_container, null_armor, 0, false, "null item", 1
    },
    {
        CREDIT, 0, 0, 1, 1,
        ITEM_CREDIT, null_weapon, null_container,null_armor, 0, false, "credit", 1
    },
    {
        METAL_ROD, 100, 15, 1, 300,
        ITEM_MELEE_WEAPON, {{1,2,3},0,false,false,false,3,2,0}, null_container, null_armor, 0, false, "metal rod", 1
    },
    {
        KNIFE, 5, 25, 1, 100,
        ITEM_MELEE_WEAPON, {{1,2,1},0,false,false,false,0,2,0}, null_container, null_armor, 0, false, "knife", 1
    },
    {
        COMBAT_KNIFE, 5, 14, 1, 500,
        ITEM_MELEE_WEAPON, {{2,2,1},5,false,false,false,0,2,0}, null_container, null_armor, 0, false, "combat knife", 1
    },
    {
        SWORD_GEN, 75, 13, 1, 20000,
        ITEM_MELEE_WEAPON, {{1,6,5},1,false,false,false,0,2,0}, null_container, null_armor, 0, false, "sword", 3
    },
    {
        SWORD_DIAMOND, 350, 3, 1, 50000,
        ITEM_MELEE_WEAPON, {{1,7,7},-4,false,false,false,5,2,4}, null_container, null_armor, 0, false, "diamond sword", 6
    },
    {
        SWORD_GIANT, 800, 2, 1, 150000,
        ITEM_MELEE_WEAPON, {{1,12,10},-16,false,false,false,5,4,0}, null_container, null_armor, 0, false, "giant sword", 5
    },
    {
        PISTOL_10MM, 15, 17, 1, 100,
        ITEM_FIREARM_WEAPON, {{1,3,4},2,false,false,false,0,2,0}, {0,8}, null_armor,0, false, "pistol", 1
    },
    {
        PISTOL_STEALTH, 20, 14, 1, 200,
        ITEM_FIREARM_WEAPON, {{1,3,2},1,true,false,false,0,2,0}, {0,10},null_armor, 0, false, "stealth pistol", 1
    },
    {
        REVOLVER, 40, 13, 1, 500,
        ITEM_FIREARM_WEAPON, {{1,14,8},0,false,false,false,0,2,3}, {0,5},null_armor, 0, false, "revolver", 2
    },
    {
        ASSAULT_RIFLE, 250, 12, 1, 1500,
        ITEM_FIREARM_WEAPON, {{1,4,5},0,false,false,false,0,2,0}, {0,30},null_armor, 0, false, "assault rifle", 1
    },
    {
        CHAINGUN, 800, 8, 1, 8000,
        ITEM_FIREARM_WEAPON, {{2,3,2},-3,false,false,false,0,2,0}, {0,60},null_armor, 0, false, "chaingun", 3
    },
    {
        COMBAT_SHOTGUN, 250, 13, 1, 1500,
        ITEM_FIREARM_WEAPON, {{3,6,7},-1,false,false,false,4,2,1}, {0,2}, null_armor,0, false, "combat shotgun", 1
    },
    {
        DOUBLEBARRELLED_SHOTGUN, 350, 7, 1, 25000,
        ITEM_FIREARM_WEAPON, {{6,12,14},-2,false,false,false,15,4,1}, {0,2}, null_armor,0, false, "double shotgun", 7
    },
    {
        ROCKET_LAUNCHER, 1250, 5, 1, 15000,
        ITEM_FIREARM_WEAPON, {{7,12,18},-15,false,true,false,8,5,4}, {0,1},null_armor, 0, false, "launcher", 4
    },
    {
        LASER_GUN, 600, 7, 1, 40000,
        ITEM_FIREARM_WEAPON, {{5,11,5},0,false,false,true,0,2,0}, {0,10},null_armor, 0, false, "laser gun", 10
    },
    {
        DEATHRAY_GUN, 500, 1, 1, 100000,
        ITEM_FIREARM_WEAPON, {{1,5,60},0,false,false,false,0,2,0}, {0,1},null_armor, 0, false, "death ray", 12
    },
    {
        FLAMETHROWER, 700, 4, 1, 10000,
        ITEM_FIREARM_WEAPON, {{3,6,2},16,false,false,true,0,2,0}, {0,7},null_armor, 0, false, "flamethrower", 1
    },
    {
        SNIPER_RIFLE, 400, 9, 1, 7500,
        ITEM_FIREARM_WEAPON, {{3,5,17},-5,false,false,false,10,2,0}, {0,1},null_armor, 0, false, "sniper rifle", 5
    },
    {
        PLASMA_CANNON, 1000, 2, 1, 300000,
        ITEM_FIREARM_WEAPON, {{4,12,25},18,false,false,true,0,2,0}, {0,3},null_armor, 0, false, "plasma cannon", 13
    },
    {
        PULSE_CANNON, 1000, 2, 1, 1000000,
        ITEM_FIREARM_WEAPON, {{3,5,8},0,false,false,false,0,2,0}, {0,3},null_armor, 0, false, "pulse cannon", 15
    },
    {
        HANDGUN_AMMO_GEN, 2, 30, 12, 5,
        ITEM_AMMUNITION, null_weapon, null_container, null_armor, 0, false, "pistol round", 1
    },
    {
        REVOLVER_AMMO, 3, 10, 6, 10,
        ITEM_AMMUNITION, null_weapon, null_container, null_armor, 0, false, "revolver round", 2
    },
    {
        ARIFLE_AMMO, 4, 10, 15, 15,
        ITEM_AMMUNITION, null_weapon, null_container, null_armor, 0, false, "cartridge", 1
    },
    {
        CHAINGUN_AMMO, 10, 5, 30, 25,
        ITEM_AMMUNITION, null_weapon, null_container, null_armor, 0, false, "chaingun bullet", 3
    },
    {
        SHOTGUN_AMMO, 9, 10, 10, 20,
        ITEM_AMMUNITION, null_weapon, null_container, null_armor, 0, false, "shotgun slug", 1
    },
    {
        LAUNCHER_AMMO, 100, 10, 5, 50,
        ITEM_AMMUNITION, null_weapon, null_container, null_armor, 0, false, "rocket", 4
    },
    {
        LASER_AMMO, 25, 7, 10, 100,
        ITEM_AMMUNITION, null_weapon, null_container, null_armor, 0, false, "laser cell", 10
    },
    {
        DEATHRAY_AMMO, 100, 1, 1, 1000,
        ITEM_AMMUNITION, null_weapon, null_container, null_armor, 0, false, "antimatter capsule", 12
    },
    {
        FLAMETHROWER_AMMO, 20, 10, 7, 30,
        ITEM_AMMUNITION, null_weapon, null_container, null_armor, 0, false, "fuel cell", 1
    },
    {
        SNIPER_AMMO, 6, 10, 4, 25,
        ITEM_AMMUNITION, null_weapon, null_container, null_armor, 0, false, "sniper cartridge", 5 
    },
    {
        PLASMA_AMMO, 30, 3, 3, 2000,
        ITEM_AMMUNITION, null_weapon, null_container, null_armor, 0, false, "plasma cell", 13
    },
    {
        PISTOL_10MM_UPGRADE, 100, 10, 1, 2000,
        ITEM_WEAPON_UPGRADE, null_weapon, null_container, null_armor, 0, false, "pistol upgrade", 1
    },
    {
        PISTOL_STEALTH_UPGRADE, 100, 7, 1, 2500,
        ITEM_WEAPON_UPGRADE, null_weapon, null_container, null_armor, 0, false, "stealth pistol upgrade", 1
    },
    {
        REVOLVER_UPGRADE, 100, 7, 1, 3000,
        ITEM_WEAPON_UPGRADE, null_weapon, null_container, null_armor, 0, false, "revolver upgrade", 4
    },
    {
        ASSAULT_RIFLE_UPGRADE, 150, 6, 1, 4000,
        ITEM_WEAPON_UPGRADE, null_weapon, null_container, null_armor, 0, false, "assault rifle upgrade", 6
    },
    {
        CHAINGUN_UPGRADE, 500, 5, 1, 5000,
        ITEM_WEAPON_UPGRADE, null_weapon, null_container, null_armor, 0, false, "chaingun upgrade", 8
    },
    {
        COMBAT_SHOTGUN_UPGRADE, 150, 6, 1, 4000,
        ITEM_WEAPON_UPGRADE, null_weapon, null_container, null_armor, 0, false, "combat shotgun upgrade", 3
    },
    {
        DOUBLEBARRELLED_SHOTGUN_UPGRADE, 600, 5, 1, 10000,
        ITEM_WEAPON_UPGRADE, null_weapon, null_container, null_armor, 0, false, "double shotgun upgrade", 10
    },
    {
        ROCKET_LAUNCHER_UPGRADE, 700, 4, 1, 7000,
        ITEM_WEAPON_UPGRADE, null_weapon, null_container, null_armor, 0, false, "launcher upgrade", 7
    },
    {
        LASER_GUN_UPGRADE, 650, 4, 1, 7600,
        ITEM_WEAPON_UPGRADE, null_weapon, null_container, null_armor, 0, false, "laser gun upgrade", 10
    },
    {
        DEATHRAY_GUN_UPGRADE, 1000, 1, 1, 15000,
        ITEM_WEAPON_UPGRADE, null_weapon, null_container, null_armor, 0, false, "death ray upgrade", 17
    },
    {
        FLAMETHROWER_UPGRADE, 350, 4, 1, 6000,
        ITEM_WEAPON_UPGRADE, null_weapon, null_container, null_armor, 0, false, "flamethrower upgrade", 4 
    },
    {
        SNIPER_RIFLE_UPGRADE, 400, 4, 1, 5000,
        ITEM_WEAPON_UPGRADE, null_weapon, null_container, null_armor, 0, false, "sniper rifle upgrade", 8
    },
    {
        PLASMA_CANNON_UPGRADE, 1500, 1, 1, 9000,
        ITEM_WEAPON_UPGRADE, null_weapon, null_container, null_armor, 0, false, "plasma cannon upgrade", 17
    },
    {
        PULSE_CANNON_UPGRADE, 4000, 1, 1, 20000,
        ITEM_WEAPON_UPGRADE, null_weapon, null_container, null_armor, 0, false, "pulse cannon upgrade", 20
    },
    {
        HEALTH_BOOSTER, 5, 3, 1, 1000,
        ITEM_STATBOOSTER, null_weapon, null_container, null_armor, 0, false, "health booster", 1
    },
    {
        STRENGTH_BOOSTER, 5, 2, 1, 1500,
        ITEM_STATBOOSTER, null_weapon, null_container, null_armor, 0, false, "strength booster", 1
    },
    {
        DEXTERITY_BOOSTER, 5, 2, 1, 1500,
        ITEM_STATBOOSTER, null_weapon, null_container, null_armor, 0, false, "dexterity booster", 1
    },
    {
        ACCURACY_BOOSTER, 5, 2, 1, 1500,
        ITEM_STATBOOSTER, null_weapon, null_container, null_armor, 0, false, "accuracy booster", 1
    },
    {
        SMALL_MEDKIT, 15, 20, 1, 25,
        ITEM_MEDKIT, null_weapon, null_container, null_armor, 0, false, "small medkit", 1
    },
    {
        LARGE_MEDKIT, 25, 10, 1, 50,
        ITEM_MEDKIT, null_weapon, null_container, null_armor, 0, false, "large medkit", 1
    },
    {
        GIANT_MEDKIT, 35, 5, 1, 100,
        ITEM_MEDKIT, null_weapon, null_container, null_armor, 0, false, "giant medkit", 1
    },
    {
        DRILL_DEVICE, 10, 3, 1, 1000,
        ITEM_DEVICE, null_weapon, null_container, null_armor, 1, false, "driller", 1
    },
    {
        MAPPING_DEVICE, 10, 3, 1, 2000,
        ITEM_DEVICE, null_weapon, null_container, null_armor, 1, false, "terrain radar", 1
    },
    {
        NPCDETECTOR_DEVICE, 10, 3, 1, 1500,
        ITEM_DEVICE, null_weapon, null_container, null_armor, 1, false, "thermal radiation detector", 1
    },
    {
        ITEMDETECTOR_DEVICE, 10, 3, 1, 2500,
        ITEM_DEVICE, null_weapon, null_container, null_armor, 1, false, "item detector", 1
    },
    {
        TELEPORT_DEVICE, 10, 3, 1, 4000,
        ITEM_DEVICE, null_weapon, null_container, null_armor, 1, false, "mini teleporter", 1
    },
    {
        TIMESTOPPER_DEVICE, 10, 1, 1, 20000,
        ITEM_DEVICE, null_weapon, null_container, null_armor, 1, false, "time stopper", 1
    },
    {
        CORRODING_DEVICE, 10, 5, 1, 50,
        ITEM_DEVICE, null_weapon, null_container, null_armor, 1, false, "exploding corrosive container", 1
    },
    {
        GRAPHENE_ARMOR, 50, 1, 1, 600,
        ITEM_ARMOR, null_weapon, null_container, {0,5,6,7},0, false, "graphene armor", 14
    },
    {
        GOLIATH_ARMOR, 1600, 1, 1, 1200,
        ITEM_ARMOR, null_weapon, null_container, {-10,10,0,0},0, false, "goliath armor", 17
    },
    {
        DIAMOND_ARMOR, 600, 2, 1, 500,
        ITEM_ARMOR, null_weapon, null_container, {-5,6,2,5},0, false, "diamond armor", 12
    },
    {
        HAZMAT_ARMOR, 80, 7, 1, 300,
        ITEM_ARMOR, null_weapon, null_container, {0,0,0,1},0, false, "hazmat suit", 1
    },
    {
        BALLISTIC_ARMOR, 150, 10, 1, 300,
        ITEM_ARMOR, null_weapon, null_container, {0,0,1,0},0, false, "ballistics armor", 1
    },
    //
    // artifacts and generally non-naturally spawned items
    //
    {
        ANCIENT_FLAIL, 1300, 0, 1, 5000000,
        ITEM_MELEE_WEAPON, {{6,7,16},-45,false,false,false,1,2,15}, null_container, null_armor, 0, true, "ancient flail", 1
    },
    {
        FUSION_CANNON, 1000, 3, 1, 10000000,
        ITEM_FIREARM_WEAPON, {{6,9,38},45,false,false,true,2,3,1}, {0,10},null_armor,0, true, "fusion cannon", 1
    },
    {
        NUCLEAR_ARMOR, 160, 1, 1, 20000000,
        ITEM_ARMOR, null_weapon, null_container, {0,0,0,150}, 0, true, "nuclear defense suit", 1
    },
    //
    // debug items (should never appear in normal game)
    //
    {
        DEBUG_ARMOR, 50, 1, 1, 60000,
        ITEM_ARMOR, null_weapon, null_container, {0,1000,1000,1000}, 0, true, "debug armor", 1
    }
};


class item
{
    public:

        item();

        item(item_stats, int);

        void decrementMiscval();

        void setMiscVal(int);

        void setQuant(int);

        void setStats(item_stats);

        void setSubContainerAmount(int);

        void decrementSubContainerAmount();

        void setChargeKnown(bool);

        int getQuant();

        bool getChargeKnown();

        item_t getType();

        item_stats *getStats();

    private:

        int quantity;

        bool chargeKnown;

        item_stats stats;
};

// can be used as an inventory, pile on the ground, or vending machine contents
class item_container
{
    public:

        item_container();

        void addToContainer(item_stats, int);

        void removeItem(int, int);

        void updateWeight();

        void deleteAllItems();

        void initContainer();

        bool isEmpty();

        int getTotalWeight();

        int getNumItems();

        int getPos(item_stats *);

        item *getItem(int);

    protected:

        VECTOR <item> items;

        int total_weight;
};

// inherits from item_container
class cell_pile : public item_container
{
    public:

        cell_pile(point);

        point getLoc();

    private:

        point loc;
};

class being_inv : public item_container
{
    public:

        being_inv();

        item *getWeapon();

        item *getArmor();

        void setWeapon(int);

        void setArmor(int);

        void setWeapon(item_stats);

        void setArmor(item_stats);

    private:

        item equipped_weapon;

        item equipped_armor;
};

bool itemsEqual(item_stats *, item_stats *);

bool isMeleeWeaponMatchMetallicArmor(item_t wep);

bool isFirearmMatchMetallicArmor(item_t wep);

bool isFirearmMatchEnergyArmor(item_t wep);

item_t weapon2ammo(item_t wep);

#endif

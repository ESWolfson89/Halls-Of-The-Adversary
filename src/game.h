#ifndef GAME_H_
#define GAME_H_

#include "level.h"
#include "output.h"
#include "input.h"
#include "pathfind.h"
#include "bresenham.h"
#include "message.h"

// unused
static const int accessible_levels[10] =
{
    1,4,7,11,14,17,20,23,29,30
};

static const uint exp_levelup_values[69] =
{
    16,
    32,
    64,
    128,
    256,
    512,
    1024,
    2048,
    4096,
    8192,
    16384,
    32768,
    65536,
    100000,
    150000,
    200000,
    250000,
    300000,
    350000,
    400000,
    450000,
    500000,
    550000,
    600000,
    650000,
    700000,
    750000,
    800000,
    850000,
    900000,
    950000,
    1000000,
    1250000,
    1500000,
    2000000,
    2500000,
    3000000,
    3500000,
    4000000,
    4500000,
    5000000,
    5500000,
    6000000,
    6500000,
    7000000,
    7500000,
    8000000,
    8500000,
    9000000,
    9500000,
    10000000,
    15000000,
    20000000,
    25000000,
    30000000,
    35000000,
    40000000,
    45000000,
    50000000,
    55000000,
    60000000,
    65000000,
    70000000,
    75000000,
    80000000,
    85000000,
    90000000,
    95000000,
    100000000
};

class Game
{
    public:

        Game();

        void initGame();

        void run();

        void promptInput();

        void primaryGameLoop();

        void reDisplayAll();

        void calculatePlayerLOS();

        void displayMappedOutLevel();

        void checkPlayerPickup(being *,item *,int,int,bool);

        void checkPlayerQuickPickup();

        void cleanup();

        void movePlayer(point);

        void changeBeingTile(point,point,NPC_t);

        void checkForLevelFeature();

        void activateAllNPCAI();

        void activateOneNPC(int);

        void deallocateGenericData(level *);

        void damageMsgeAdd(STRING, item_t, chtype, chtype, bool, bool, bool, bool, int);

        void msgeAdd(STRING, color_pair);

        void executeMiscPlayerTurnBasedData();

        void executeMiscNPCTurnBasedData();

        void checkNPCDefeatedEvents();

        void checkPlayerDefeatedEvents();

        void flashNPCDeathSprite(being *);

        void printPlayerStats();

        void NPCGetRandomTargetDestination(being *);

        void setupPlayer();

        void melee(being *, being *);

        void addHitMissIndicatorMessage(being *, being *, bool);

        bool confirmMelee(being *);

        void playerEquipWeapon(STRING, int);

        void playerWearArmor(STRING, int);

        void damageBeing(being *, point, int);

        void damagePlayer(being *, int);

        void damageNPC(being *, point, int);

        void checkIfTargetIsHostile(being *, being *);

        void checkNPCHeal(being *);

        void checkNPCNeutrality(being *);

        void checkNPCElusion(being *);

        void checkNPCMiscEvent(being *);

        bool checkNPCTeleportEvent(being *);

        bool checkNPCExplodeAttackEvent(being *);

        bool checkNPCFireNonWeaponProjectile(being *);

        void buyFromArmsDealer(being *);

        void examineItemFromArmsDealer(int, int, being *);

        bool checkNPCFightEvent(being *);

        bool checkNPCPickupEvent(being *);

        bool checkNPCSpecialEvent(being *);

        bool checkNPCMiscAttackEvent(being *, being *);

        void NPCShout(being *);

        void alertNPC(being *, int);

        void moveNPC(being *, point);

        void dropItems(being *, int, int);

        void pickUpItems(being *, int, int);

        void beingDropAllItems(being *, point, bool);

        void examineItemList(item_list_category, point);

        void printMessageAndWaitForSpace(STRING);

        void printPickupMessage(being *, int, STRING);

        void checkForAlertingNPCs(point,point);

        void resetBeingAttackAndFleeIDs(int);

        void chatWithNPC();

        bool checkPlayerUseItem(int);

        bool checkNPCEquipEvent(being *);

        void setCustomCellColors();

        void checkExperience(being *, uint);

        void checkAttributeChange(being*, int);

        void msgeAddPromptSpace(STRING, color_pair);

        void gotoHelpScreen();

        bool beingReloadFirearm(being *);

        void playerReloadFirearm();

        void NPCOpenDoor(being *, point);

        int getPotentialFleeID(int);

        STRING actionToMessage(being *, STRING);

        STRING speechToMessage(being *, STRING);

        STRING getNameToPrint(being *, bool, bool);

        void NPCMessage(being *, STRING, bool);

        void playerFireWeaponToggle(bool);

        void beingFireWeapon(being *, point);

        void printPlayerFirePath(point,point);

        void shootProjectile(being *, point, item_t, int, int, int);

        void shootBurst(being *, point, item_t, Uint32);

        void extrapolateLine(point &, point &);

        void outputLOFTransition(int, item_t, point, point, point);

        void clearAllFireCells();

        void clearFireInRange(point, int);

        void damageBeingFromWeapon(int, point, being *, being *);

        void checkForBeingStateEvent(being *, being *, bool);

        void useFeaturePlayer(point);

        void createExplosion(being *, dice_roll, point, bool);

        void projectileHit(point, being *, item_t, bool, bool, int);

        void damageBeingFromExplosion(being *, being *, point, int, bool,bool);

        void delayAndUpdate(int);

        void delayAndUpdateOnly(int);

        void shootBurst(being *, point, item_t, int);

        void shootSniper(being *, point);

        void shootPulse(being *, point, item_t);

        bool checkNPCCircularDeathRayEvent(being *);

        bool checkNPCBulldozeEvent(being *);

        bool checkNPCWallinEvent(being *);

        void NPCCommunicate(being *, NPC_t, bool);

        void useDevice(being *, int);

        void enterDebugMode();

        void checkForCreateVaultAgent();

        void confrontAgent(being *);

        void upgradeEquippedWeapon(being *, int);

        void upgradeAttributes(being *, int);

        void useMedkit(being *, int);

        void gotoPrevLevel();

        void gotoNextLevel();

        void changeLevel(int,lev_type);

        void printTerrainData();

        void setupAllies();

        void playerUseDrill(int);

        void playerUseMap(int);

        void playerUseCorroder(int);

        void quitGame();

        point getNextTargetedEnemy(int&);

        int checkForCriticalHit(item *, bool);

        bool checkForBeingInLOF(int, point, being *);

        bool checkNPCFireWeaponEvent(being *, point);

        bool checkNPCSummonEvent(being *);

        bool beingUndetectedChance(being *, bool);

        bool isTargetableEnemy(int);

        bool useFeatureAtPlayer(point);

        bool checkNPCStealEvent(being *, being *);

        void showLevelFeature(point);

        void setSpecialNPCAttackMovement(being *, being *);

        void deallocateGameData();

        void reDisplayRightScreenSide();

        void swapPlaces(being *, being *);

        void displayAllNPCs();

        void playerUseNPCDetector(int);

        void displayAllItems();

        void playerUseItemDetector(int);

        void playerUseTeleport(int);

        void decrementDeviceCounter(being *, int);

        void moveCursor(bool);

        void checkForDestroyingTerrain(point);

        void setNPCAIActivation(bool, int);

        void playerUseTimeStopper(int);

        void checkForStunEvent(being *, being *, int, bool);

        void checkForDrainLifeEvent(being *, being*);

        void addStartingAllies();

        void moveAllies();

        bool checkNPCStaggerEvent(being *);

        bool playerAttemptStunRestrictedEvent();

        being *getPlayer();

        being *getCurrentNPCTurn();

        point getFleeLoc(point);

        map *getMap();

        being *getBeingAt(point);

        void promptMainMenu();
        // debug functions
        void assertNPCFieldsValidity(being *);

        void displayNPCErrorScreen(being *, STRING, STRING);

        void useSatellitePlayer(satellite *);

        bool sendSatelliteSignal(satellite *);

        void checkForSpecLevelEvent();

        void promptUseSidewaysElevator();

        void promptEnterArchway();

        void initItemMaps();

        terrain_t terrainAt(point);

        item_t itemAt(point);

        NPC_t NPCAt(point);

        fire_t fireAt(point);

        void setTerrainAt(point, terrain_t);

        void setItemAt(point, item_t);

        void setNPCAt(point, NPC_t);

        void setFireAt(point, fire_t);

        void printCustomNPCSymbols();

        void printCustomItemSymbols();

        void createDeathExplosion(being *, point);

        point playerAt();

        being* getBeing(int);

        point beingAt(int);

        being_inv* playerInventory();

        item * playerWeapon();

        item * playerArmor();

        // template functions
        template <typename M> void useMachinePlayer(M*);

        template <typename M> void featurePlayerSelect(M*);

        template <typename M> void featurePlayerToggle(M*);

    private:

        VECTOR<being> followingAllies;

        VECTOR<level> mainLevels;

        level spiralVaultLevel;

        level yinaximaiLevel;

        level level_obj;

        input ibuf;

        mapdisplay disp;

        bool program_executing;

        bool game_active;

        bool player_has_moved;

        bool player_last_attack;

        being player;

        pathfind pfinder;

        integer_line linetracer;

        msgbuffer mbuf;

        npcdamagebuffer dbuf;

        int level_number;

        int level_index;

        int last_active_id;

        int AI_stop_counter;

        int gbti;

        int last_regular_level;

        bool debug_mode;

        bool summoned_agent;

        bool wayback_unlocked;

        int num_game_turns;

        point player_quick_fire_spot;

        IdentificationData deviceIdData;
};

int baseMeleeDamage(being *);

int getArmorProtectionValue(being *, being*, bool, bool, bool);

bool baseHitChance(being *, being *, bool);

bool calculateFleeChance(being *);

bool canPickupItem(being *, item *, int);

bool canAlert(NPC_t, NPC_t);

double getWeaponCost(item_stats *);

double getArmorCost(item_stats *);

uint64 getItemCost(item_stats *, int, int);

STRING damageStatusString(being *);

STRING deathMessage(being *);

STRING playerPainStatus(int);

STRING getGenderPrefix(being_gender);

STRING getDeterminer(STRING);

chtype getExactSymbolFromNPC(being *);

being_inv* inventory(being *);

void clearInventory(being *);

void setWeapon(being *, const item_stats);

void setWeapon(being*, int i);

void setArmor(being *, const item_stats);

void setArmor(being *, int i);

void addToInventory(being *, item_stats, int);

void setCredits(being*, uint64);

void incCredits(being*, uint64);

void decCredits(being*, uint64);

uint64 credits(being *);

point beingAt(being *);

item* weapon(being*);

item* armor(being*);

being_stats * beingStats(being *);

item_stats* itemStats(item *);

dice_roll getDeathExplosionDamage(being *);

#endif

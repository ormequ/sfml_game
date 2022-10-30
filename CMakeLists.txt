cmake_minimum_required(VERSION 3.16)
project(game)

set(CMAKE_CXX_STANDARD 14)

set(SFML_DIR "C:\\Program Files\\SFML\\lib\\cmake\\SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories(.)
include_directories(src/kernel/events)
include_directories(src/kernel/field)
include_directories(src/kernel/creatures)

add_executable(game
        src/kernel/field/Cell.cpp src/kernel/field/Cell.h
        src/kernel/field/Field.cpp src/kernel/field/Field.h
        src/kernel/creatures/Player.cpp src/kernel/creatures/Player.h
        src/main.cpp src/view/ViewController.cpp src/view/ViewController.h
        src/Point.cpp src/Point.h
        src/view/KeyboardHandler.cpp src/view/KeyboardHandler.h
        src/view/draw/DrawManager.cpp src/view/draw/DrawManager.h
        src/view/draw/TextureManager.cpp src/view/draw/TextureManager.h
        src/events/IEvent.h
        src/kernel/creatures/CreatureManager.cpp src/kernel/creatures/CreatureManager.h
        src/GameMediator.cpp src/GameMediator.h
        src/view/draw/field/FieldDrawer.cpp src/view/draw/field/FieldDrawer.h
        src/GameController.cpp src/GameController.h
        src/kernel/KernelController.cpp src/kernel/KernelController.h src/view/draw/HUD/HudDrawer.cpp src/view/draw/HUD/HudDrawer.h src/mapmaker/MapMaker.cpp src/mapmaker/MapMaker.h src/events/EventsController.cpp src/events/EventsController.h src/view/draw/IDrawer.h src/events/IEventFactory.h src/view/draw/field/CellSpriteGetter.cpp src/view/draw/field/CellSpriteGetter.h src/events/cells/CellsEvent.cpp src/events/cells/CellsEvent.h src/events/cells/CellsImprisonEvent.cpp src/events/cells/CellsImprisonEvent.h src/events/cells/CellsEventFactory.cpp src/events/cells/CellsEventFactory.h src/events/player/PlayerEvent.cpp src/events/player/PlayerEvent.h src/events/player/PlayerHealEvent.cpp src/events/player/PlayerHealEvent.h src/events/player/PlayerBeatEvent.cpp src/events/player/PlayerBeatEvent.h src/events/player/PlayerEventFactory.cpp src/events/player/PlayerEventFactory.h src/events/EventChainLink.cpp src/events/EventChainLink.h src/GameStateController.cpp src/GameStateController.h src/events/game_state/GameStateEvent.cpp src/events/game_state/GameStateEvent.h src/events/game_state/GameWinEvent.cpp src/events/game_state/GameWinEvent.h src/events/game_state/GameStateEventFactory.cpp src/events/game_state/GameStateEventFactory.h src/events/EmptyEvent.cpp src/events/EmptyEvent.h src/logger/LoggerController.cpp src/logger/LoggerController.h src/logger/ISubscriber.h src/logger/LoggerMessage.cpp src/logger/LoggerMessage.h src/logger/AbstractObserver.cpp src/logger/AbstractObserver.h src/logger/observers/proxy/EventProxy.cpp src/logger/observers/proxy/EventProxy.h src/logger/observers/proxy/PlayerProxy.cpp src/logger/observers/proxy/PlayerProxy.h src/kernel/creatures/ICreature.h src/kernel/creatures/IObject.h src/kernel/creatures/CreatureParam.h src/logger/loggers/ILogger.h src/logger/loggers/ConsoleLogger.cpp src/logger/loggers/ConsoleLogger.h 
        src/logger/LogLevel.cpp src/logger/LogLevel.h src/kernel/field/IField.h src/logger/observers/proxy/FieldProxy.cpp src/logger/observers/proxy/FieldProxy.h src/logger/loggers/FileLogger.cpp src/logger/loggers/FileLogger.h src/logger/observers/ErrorsObserver.cpp src/logger/observers/ErrorsObserver.h src/logger/observers/proxy/GameStateProxy.cpp src/logger/observers/proxy/GameStateProxy.h src/IGameState.h src/events/map/MapEvent.cpp src/events/map/MapEvent.h src/events/map/MapEventFactory.cpp src/events/map/MapEventFactory.h src/events/map/MapMakeForestEvent.cpp src/events/map/MapMakeForestEvent.h)


target_link_libraries(game sfml-graphics sfml-audio)

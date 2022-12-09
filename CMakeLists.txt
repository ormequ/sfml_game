cmake_minimum_required(VERSION 3.16)
project(game)

set(CMAKE_CXX_STANDARD 17)

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
        src/view/handler/KeyboardHandler.cpp src/view/handler/KeyboardHandler.h
        src/view/draw/DrawManager.cpp src/view/draw/DrawManager.h
        src/view/draw/TextureManager.cpp src/view/draw/TextureManager.h
        src/events/IEvent.h
        src/kernel/creatures/CreatureManager.cpp src/kernel/creatures/CreatureManager.h
        src/GameMediator.cpp src/GameMediator.h
        src/view/draw/field/FieldDrawer.cpp src/view/draw/field/FieldDrawer.h
        src/GameController.cpp src/GameController.h
        src/kernel/KernelController.cpp src/kernel/KernelController.h src/view/draw/HUD/HudDrawer.cpp src/view/draw/HUD/HudDrawer.h src/events/EventsController.cpp src/events/EventsController.h src/view/draw/IDrawer.h src/events/IEventFactory.h src/view/draw/field/CellSpriteGetter.cpp src/view/draw/field/CellSpriteGetter.h src/events/cells/CellsEvent.cpp src/events/cells/CellsEvent.h src/events/cells/CellsImprisonEvent.cpp src/events/cells/CellsImprisonEvent.h src/events/cells/CellsEventFactory.cpp src/events/cells/CellsEventFactory.h src/events/player/PlayerEvent.cpp src/events/player/PlayerEvent.h src/events/player/PlayerHealEvent.cpp src/events/player/PlayerHealEvent.h src/events/player/PlayerBeatEvent.cpp src/events/player/PlayerBeatEvent.h src/events/player/PlayerEventFactory.cpp src/events/player/PlayerEventFactory.h src/events/EventChainLink.cpp src/events/EventChainLink.h src/GameStateController.cpp src/GameStateController.h src/events/game_state/GameStateEvent.cpp src/events/game_state/GameStateEvent.h src/events/game_state/GameWinEvent.cpp src/events/game_state/GameWinEvent.h src/events/game_state/GameStateEventFactory.cpp src/events/game_state/GameStateEventFactory.h src/events/EmptyEvent.cpp src/events/EmptyEvent.h src/logger/LoggerController.cpp src/logger/LoggerController.h src/logger/ISubscriber.h src/logger/LoggerMessage.cpp src/logger/LoggerMessage.h src/logger/AbstractObserver.cpp src/logger/AbstractObserver.h src/logger/observers/proxy/EventProxy.cpp src/logger/observers/proxy/EventProxy.h src/logger/observers/proxy/PlayerProxy.cpp src/logger/observers/proxy/PlayerProxy.h src/kernel/creatures/ICreature.h src/kernel/creatures/IObject.h src/kernel/creatures/CreatureParam.h src/logger/loggers/ILogger.h src/logger/loggers/ConsoleLogger.cpp src/logger/loggers/ConsoleLogger.h
        src/logger/LogLevel.cpp src/logger/LogLevel.h src/kernel/field/IField.h src/logger/observers/proxy/FieldProxy.cpp src/logger/observers/proxy/FieldProxy.h src/logger/loggers/FileLogger.cpp src/logger/loggers/FileLogger.h src/logger/observers/ErrorsObserver.cpp src/logger/observers/ErrorsObserver.h src/logger/observers/proxy/GameStateProxy.cpp src/logger/observers/proxy/GameStateProxy.h src/IGameState.h src/events/map/MapEventFactory.cpp src/events/map/MapEventFactory.h src/events/map/MapMakeForestEvent.cpp src/events/map/MapMakeForestEvent.h src/view/handler/CommandCreator.cpp src/view/handler/CommandCreator.h src/view/handler/reader/IHandlerReader.h src/view/handler/reader/HandlerFileReader.cpp src/view/handler/reader/HandlerFileReader.h src/view/handler/commands/MoveUpCommand.cpp src/view/handler/commands/MoveUpCommand.h src/view/handler/commands/MoveDownCommand.cpp src/view/handler/commands/MoveDownCommand.h src/view/handler/commands/MoveLeftCommand.cpp src/view/handler/commands/MoveLeftCommand.h src/view/handler/commands/MoveRightCommand.cpp src/view/handler/commands/MoveRightCommand.h src/view/handler/commands/ICommand.h src/mapmaker/rules/ChangeMapRule.h src/mapmaker/rules/WinRule.h src/mapmaker/rules/ObstaclesRule.h src/mapmaker/MapGenerator.h src/mapmaker/rules/CreateFieldRule.h src/mapmaker/rules/PlayerPositionRule.h src/mapmaker/rules/FallRule.h src/mapmaker/rules/AidKitRule.h src/mapmaker/rules/TrapButtonRule.h src/mapmaker/MapPresetsCollector.cpp src/mapmaker/MapPresetsCollector.h src/memento/MementoController.cpp src/memento/MementoController.h src/memento/Snapshot.cpp src/memento/Snapshot.h src/memento/SnapshotsCollector.cpp src/memento/SnapshotsCollector.h src/memento/KernelSerializer.cpp src/memento/KernelSerializer.h src/memento/EventsSerializer.cpp src/memento/EventsSerializer.h src/events/FactoryNames.h src/view/handler/commands/SaveCommand.cpp src/view/handler/commands/SaveCommand.h src/view/handler/commands/LoadCommand.cpp src/view/handler/commands/LoadCommand.h src/memento/MementoException.cpp src/memento/MementoException.h)


target_link_libraries(game sfml-graphics sfml-audio)
target_compile_features(game PRIVATE cxx_std_17)

#pragma once

class MapManager : public ManagerImpl
{
    URHO3D_OBJECT( MapManager, ManagerImpl );
public:
    //! Constructor.
    MapManager( Context* context );

    //! Deconstructor.
    ~MapManager();

    //! Initialize Object.
    bool Init();

    //! UnInitialize Object.
    void UnInit();

    //! Load Map.
    bool Load( const MapID& mapID );

    //! Map Getter.
    BaseMap* GetMap( const MapID& mapID );

    //! Current Map Getter.
    const MapID& GetCurrentMapID() const{ return curMap_.second_; }

    //! Next Map Getter.
    const MapID& GetNextMapID() const{ return nextMap_.second_; }
private:
    //! Register Load Triggers.
    void NodeRegisterLoadTriggers( Node *node );

    //! Load Trigger Entered Handler.
    void HandleLoadTriggerEntered( StringHash eventType, VariantMap& eventData );
private:
    HashMap<int, SharedPtr<BaseMap>> maps_;  //!< Maps List.
    Pair<WeakPtr<Node>,MapID> curMap_;   //!< Current Map.
    Pair<WeakPtr<Node>,MapID> nextMap_;  //!< Next Map.
};
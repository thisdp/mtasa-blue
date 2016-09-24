/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*               (Shared logic for modifications)
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        mods/shared_logic/CClientVehicleManager.h
*  PURPOSE:     Vehicle entity manager class header
*  DEVELOPERS:  Christian Myhre Lundheim <>
*               Ed Lyons <eai@opencoding.net>
*               Jax <>
*               Kevin Whiteside <kevuwk@gmail.com>
*               Cecill Etheredge <ijsf@gmx.net>
*
*****************************************************************************/

#ifndef __CCLIENTVEHICLEMANAGER_H
#define __CCLIENTVEHICLEMANAGER_H

#include "CClientVehicle.h"

class CClientManager;
class CClientVehicle;

extern const SFixedArray < unsigned char, 212 > g_ucMaxPassengers;

class CClientVehicleManager
{
public:
    ZERO_ON_NEW
                                    CClientVehicleManager   ( CClientManager* pManager );
                                    ~CClientVehicleManager  ( void );

    void                            DeleteAll               ( void );

    inline unsigned int             Count                   ( void )                        { return static_cast < unsigned int > ( m_List.size () ); };
    static CClientVehicle*          Get                     ( ElementID ID );
    CClientVehicle*                 Get                     ( CVehicle* pVehicle, bool bValidatePointer );
    CClientVehicle*                 GetSafe                 ( CEntity * pEntity );
    CClientVehicle*                 GetClosest              ( CVector& vecPosition, float fRadius );

    void                            DoPulse                 ( void );

    static bool                     IsTrainModel            ( unsigned long ulModel );
    static bool                     IsValidModel            ( unsigned long ulModel );
    static eClientVehicleType       GetVehicleType          ( unsigned long ulModel );
    static unsigned char            GetMaxPassengerCount    ( unsigned long ulModel );
    static unsigned char            ConvertIndexToGameSeat  ( unsigned long ulModel, unsigned char ucIndex );
    static void                     GetRandomVariation      ( unsigned short usModel, unsigned char &ucVariant, unsigned char &ucVariant2 );

    static bool                     HasTurret               ( unsigned long ulModel );
    static bool                     HasSirens               ( unsigned long ulModel );
    static bool                     HasLandingGears         ( unsigned long ulModel );
    static bool                     HasAdjustableProperty   ( unsigned long ulModel );
    static bool                     HasSmokeTrail           ( unsigned long ulModel );
    static bool                     HasTaxiLight            ( unsigned long ulModel );
    static bool                     HasSearchLight          ( unsigned long ulModel );
    static bool                     HasDamageModel          ( unsigned long ulModel );
    static bool                     HasDamageModel          ( enum eClientVehicleType Type );
    static bool                     HasDoors                ( unsigned long ulModel );

    bool                            Exists                  ( CClientVehicle* pVehicle );

    static bool                     IsVehicleLimitReached   ( void );

    void                            RestreamVehicles        ( unsigned short usModel );
    void                            RestreamVehicleUpgrades ( unsigned short usModel );

    const CMappedArray < CClientVehicle* > & GetVehicles(void)         { return m_List; }
    const CMappedArray < CClientVehicle* > & GetStreamedVehicles(void) { return m_StreamedIn; }


    inline void                     AddToList               ( CClientVehicle* pVehicle )    { m_List.push_back ( pVehicle ); };
    void                            RemoveFromLists         ( CClientVehicle* pVehicle );

    void                            OnCreation              ( CClientVehicle* pVehicle );
    void                            OnDestruction           ( CClientVehicle* pVehicle );

protected:

    CClientManager*                 m_pManager;
    bool                            m_bCanRemoveFromList;
    CMappedArray < CClientVehicle* >  m_List;
    CMappedArray < CClientVehicle* >  m_StreamedIn;
};

#endif
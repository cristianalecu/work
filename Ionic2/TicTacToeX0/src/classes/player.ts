export enum PlayerType 
{ User, Computer, Deleted
, LAN, Bluetooth   // for tuture use
}

export type tPlayer = { name: string, id: number, pType: PlayerType, email?: string };


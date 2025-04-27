import * as UE from 'ue'

class TS_Player extends UE.Character {
    Constructor() {
        //...
    }

    ReceiveBeginPlay(): void {
        console.warn("TS_Player::BeginPlay()");
    }
    ReceiveTick(InDeltaSeconds: number): void {
        //...
    }
    //...
}

export default TS_Player;
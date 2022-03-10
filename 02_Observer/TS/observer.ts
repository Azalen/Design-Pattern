interface Beobachter {
  update(subjekt: Subjekt): void;
}

interface Subjekt {
  meldeAn(beobachter: Beobachter): void;
  meldeAb(beobachter: Beobachter): void;
  benachrichtige(): void;
}

class KonkretesSubjekt implements Subjekt {
  private beobachterList: Array<Beobachter> = [];
  public subjektZustand: string = "initial state";

  public meldeAn(beobachter: Beobachter): void {
      this.beobachterList.push(beobachter);
  }

  public meldeAb(beobachter: Beobachter): void {
      let index = this.beobachterList.indexOf(beobachter);
      if (index > -1) {
          this.beobachterList.splice(index, 1);
      }
  }

  public benachrichtige() {
      this.beobachterList.forEach(element => {
          element.update(this);
      });
  }
  
  public setzeZustand(neuerZustand: any){
      this.subjektZustand = neuerZustand;
      console.log("Subjekt    : Subjektzustand hat sich geändert!");
      this.benachrichtige();
  }
}


class KonkreterBeobachter implements Beobachter {

  beobachteterZustand: any;
  public update(subjekt: Subjekt): void {
      this.beobachteterZustand = (<KonkretesSubjekt>subjekt).subjektZustand;
      console.log("Beobachter : Subjektzustand hat sich geändert!");
      console.log("   Neuer Zustand: " + this.beobachteterZustand)
  }
}

let testSubjekt = new KonkretesSubjekt();
let logBeobachter = new KonkreterBeobachter();

testSubjekt.meldeAn(logBeobachter);
testSubjekt.setzeZustand("new state")
testSubjekt.meldeAb(logBeobachter);

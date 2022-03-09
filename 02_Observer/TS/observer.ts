class Subjekt {
  private _beobachter: Array<IBeobachter> = [];
  
  constructor(){
    this._beobachter = [];
  }
  
  public register(beobachter: IBeobachter): void {
    this._beobachter.push(beobachter);
  }
  
  public unregister(beobachter: IBeobachter): void {
    let index = this._beobachter.indexOf(beobachter);
    if(index > -1) {
      this._beobachter.splice(index, 1);
    }
  }
  
  public notify(nachricht: string){
    this._beobachter.forEach((b) => {
      b.update(nachricht);
    });
  }
}

interface IBeobachter {
  update(nachricht: string): void;
}

class LogBeobachter implements IBeobachter {
  
  public update(nachricht: string): void {
    console.log(`LOG: ${nachricht}`);
  }
}

class InfoBeobachter implements IBeobachter {
  
  public update(nachricht: string): void {
    console.info(`INFO: ${nachricht}`);
  }
}

let testSubjekt = new Subjekt();

let logBeobachter = new LogBeobachter();
let logBeobachter2 = new LogBeobachter();
let infoBeobachter = new InfoBeobachter();

testSubjekt.register(logBeobachter);
testSubjekt.notify('Wichtige Nachricht 1');
// Ausgabe
// LOG: Wichtige Nachricht 1

testSubjekt.register(logBeobachter2);
testSubjekt.register(infoBeobachter);
testSubjekt.notify('Wichtige Nachricht 2');
// Ausgabe
// LOG: Wichtige Nachricht 2
// LOG: Wichtige Nachricht 2
// INFO: Wichtige Nachricht 2

testSubjekt.unregister(logBeobachter2);
testSubjekt.notify('Wichtige Nachricht 3');
// Ausgabe
// LOG: Wichtige Nachricht 3
// INFO: Wichtige Nachricht 3

testSubjekt.unregister(logBeobachter);
testSubjekt.unregister(infoBeobachter);
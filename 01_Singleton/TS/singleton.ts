class Singleton {
    static uniqueInstance: Singleton;
  
    constructor() {
      if (Singleton.uniqueInstance !== undefined) {
        return Singleton.uniqueInstance
      }
      Singleton.uniqueInstance = this;
    }
  }
  
  var instanceOne = new Singleton()
  var instanceTwo = new Singleton()
  
  console.log(instanceOne === instanceTwo)
class Singleton {
    public:
        static Singleton* Instance();       // Klassenmethode
    private:
        Singleton();                        // Konstruktor
        static Singleton* uniqueInstance;   // Zeiger auf singuläres Objekt
}; 
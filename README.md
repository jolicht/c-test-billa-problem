# c-test-billa-problem

## Implementierungsdetails

* `customer` und `waitingLine` als unterschiedliche Entitäten implementiert, um eher den realen Entitäten zu entsprechen
* via `switchWaitingLine` werden Kunden nur mehr zwischen Warteschlangen verschoben und nicht zerstört und neu instanziert
* via `releaseFirstFromWaitingLine` werden Kunden dann tatsächlich aus der Warteschlange entfernt und sind nicht mehr existent

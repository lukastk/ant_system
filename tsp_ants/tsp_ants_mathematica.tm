:Begin:
:Function:       startSimulation
:Pattern:        StartSimulation[edgeDistancesData_List, baseTrail_Real, alpha_Real, beta_Real, q_Real, pheromoneDecay_Real]
:Arguments:      { edgeDistancesData, baseTrail, alpha, beta, q, pheromoneDecay }
:ArgumentTypes:  { RealList, Real, Real, Real, Real, Real }
:ReturnType:     Integer
:End:
:Evaluate: StartSimulation::usage = "StartSimulation[edgeDistancesData_List, baseTrail_Real, alpha_Real, beta_Real, q_Real, pheromoneDecay_Real] initializes the simulation with the given parameters"

:Begin:
:Function:       updateSimulation
:Pattern:        UpdateSimulation[]
:Arguments:      { }
:ArgumentTypes:  { }
:ReturnType:     Real
:End:

:Begin:
:Function:       updateSimulation
:Pattern:        UpdateSimulation[ticks_Integer]
:Arguments:      { ticks }
:ArgumentTypes:  { Integer }
:ReturnType:     Integer
:End:
:Evaluate: UpdateSimulation::usage = "UpdateSimulation[] updates the simulation for a single cycle.\nUpdateSimulation[ticks_Integer] updates the simulation for the specified amount of cycles."

:Begin:
:Function:       getEdgeTraces
:Pattern:        GetEdgeTraces[]
:Arguments:      { }
:ArgumentTypes:  { }
:ReturnType:     Manual
:End:
:Evaluate: GetEdgeTraces::usage = "GetEdgeTraces[] returns a matrix of the level of trace on each edge."

:Begin:
:Function:       addAnt
:Pattern:        AddAnt[town_Integer]
:Arguments:      { town }
:ArgumentTypes:  { Integer }
:ReturnType:     Integer
:End:
:Evaluate: AddAnt::usage = "AddAnt[town_Integer] adds an ant to the specified town."

:Begin:
:Function:       getNumberOfAnts
:Pattern:        GetNumberOfAnts[]
:Arguments:      { }
:ArgumentTypes:  { }
:ReturnType:     Integer
:End:
:Evaluate: GetNumberOfAnts::usage = "GetNumberOfAnts[] returns the number of ants in the simulation."

:Begin:
:Function:       getNumberOfTowns
:Pattern:        GetNumberOfTowns[]
:Arguments:      { }
:ArgumentTypes:  { }
:ReturnType:     Integer
:End:
:Evaluate: GetNumberOfTowns::usage = "GetNumberOfTowns[] returns the number of towns in the simulation."

:Begin:
:Function:       getNumberOfCycles
:Pattern:        GetNumberOfCycles[]
:Arguments:      { }
:ArgumentTypes:  { }
:ReturnType:     Integer
:End:
:Evaluate: GetNumberOfTowns::usage = "GetNumberOfCycles[] returns the number of cycles that has passed so far in the simulation."

:Begin:
:Function:       getAntPathHistories
:Pattern:        GetAntPathHistories[]
:Arguments:      { }
:ArgumentTypes:  { }
:ReturnType:     Manual
:End:
:Evaluate: GetAntPathHistories::usage = "GetAntPathHistories[] returns a list of all paths that has been traversed by the ants, in the simulation so far. Calling the function will flush the path history."

:Begin:
:Function:       getAntPathLengthHistories
:Pattern:        GetAntPathLengthHistories[]
:Arguments:      { }
:ArgumentTypes:  { }
:ReturnType:     Manual
:End:
:Evaluate: GetAntPathLengthHistories::usage = "GetAntPathLengthHistories[] returns a list of all lengths of the paths that has been traversed by the ants, in the simulation so far. Calling the function will flush the path length history."

:Begin:
:Function:       endSimulation
:Pattern:        EndSimulation[]
:Arguments:      { }
:ArgumentTypes:  { }
:ReturnType:     Integer
:End:
:Evaluate: EndSimulation::usage = "EndSimulation[] ends the simulation."

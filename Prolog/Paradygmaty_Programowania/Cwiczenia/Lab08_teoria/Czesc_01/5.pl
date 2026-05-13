kot(mruczek).
pies(reks).
pies(azor).
ptak(tweety).
zwierze_domowe(X) :- kot(X).
zwierze_domowe(X):-pies(X).
zwierze_domowe(X) :- (kot(X),pies(X), \+ptak(X)).
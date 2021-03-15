# mortgage_hacking
So, I saw this video on tic-tok where the creator claimed that it was smarter to use your down payment on the second payment instead of as a down payment. Before I believed him I had to model it for myself so I created this repo.

Was he right? I did an experiment:

## Scenario 1: Mortgage is 396,000 with a second payment of 40,000.

    Loan Finished in 25.500000 years.
    Total of Payments: 519694.744830

## Scenario 2: Mortgage is 356,000 (using the 40,000 for a down payment).

    Loan Finished in 30.0 years.
    Total of Payments: 551449.565304

So, at first it appears he was correct. With a second payment of 40k the loan is finished 5 years earlier saving $31,754.82 over a 40k down payment. The problem with this logic however is that often your loan interest rate is determined partially by the amount of your down payment. It's likely that if you don't put your 40k down you'll have to take a loan with a higher rate. The only solution is to carefully model all of the scenarios available to you. Perhaps if you have strong enough credit your rate won't be too negatively affected.

# compiling
Compile with the normal CMake method:

    mkdir -p build && pushd build && cmake .. && make && popd


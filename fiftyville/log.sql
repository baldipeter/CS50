-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Start with the reports
SELECT * FROM crime_scene_reports;
-- Check interviews
SELECT * FROM interviews
WHERE year = 2023 AND month = 7 AND day = 28;

-- Check bakery security based on what Ruth said -> license_plate for people?
SELECT * FROM bakery_security_logs
WHERE year = 2023 AND month = 7 AND day = 28
AND hour = 10 AND minute BETWEEN 15 AND 25;

-- Check ATM based on Eugene -> id from bank accounts for people?
SELECT * FROM atm_transactions
WHERE year = 2023 AND month = 7 AND day = 28
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';

-- Check phone calls based on Raymond -> phone_number, passport for people?
SELECT * FROM phone_calls
WHERE year = 2023 AND month = 7 AND day = 28
AND duration < 60;

SELECT * FROM flights
WHERE year = 2023 AND month = 7 AND day = 29
AND origin_airport_id = (
    SELECT id FROM airports
    WHERE city = 'Fiftyville'
)
ORDER BY hour;


-- All together the thief's identity comes to light:
SELECT * FROM people
WHERE license_plate IN (
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2023 AND month = 7 AND day = 28
    AND hour = 10 AND minute BETWEEN 15 AND 25
    AND activity = 'exit'
)
AND id IN (
    SELECT person_id FROM bank_accounts
    WHERE account_number IN (
        SELECT account_number FROM atm_transactions
        WHERE year = 2023 AND month = 7 AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'
    )
)
AND phone_number IN (
    SELECT caller FROM phone_calls
    WHERE year = 2023 AND month = 7 AND day = 28
    AND duration < 60
)
AND passport_number IN (
    SELECT passport_number FROM passengers
    WHERE flight_id = (
        SELECT id FROM flights
        WHERE year = 2023 AND month = 7 AND day = 29
        AND origin_airport_id = (
            SELECT id FROM airports
            WHERE city = 'Fiftyville'
        )
        ORDER BY hour, minute
        LIMIT 1
    )
);

-- Where he escaped:
SELECT city FROM flights
JOIN airports
ON flights.destination_airport_id = airports.id
WHERE year = 2023 AND month = 7 AND day = 29
AND origin_airport_id = (
    SELECT id FROM airports
    WHERE city = 'Fiftyville'
)
ORDER BY hour, minute
LIMIT 1;

-- Accomplice:
SELECT name FROM people
WHERE phone_number IN (
    SELECT receiver FROM phone_calls
    WHERE year = 2023 AND month = 7 AND day = 28
    AND duration < 60
    AND caller = (
        SELECT phone_number FROM people
        WHERE name = 'Bruce'
    )
);

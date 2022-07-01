-- Keep a log of any SQL queries you execute as you solve the mystery.

--Pull the description that matches the theft date and location

SELECT description
FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2021 AND street = "Humphrey Street";

-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time.
-- Each of their interview transcripts mentions the bakery

SELECT name, transcript
FROM interviews JOIN crime_scene_reports ON interviews.id = crime_scene_reports.id
WHERE interviews.day = 28 AND interviews.month = 7 AND interviews.year = 2021;

/*
|Ruth| Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
       If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
|Eugene| I don't know the thief's name, but it was someone I recognized.
         Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
|Raymond| As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
          In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
          The thief then asked the person on the other end of the phone to purchase the flight ticket.
*/

--Check bakery security

SELECT *
FROM bakery_security_logs
WHERE bakery_security_logs.day = 28 AND bakery_security_logs.month = 7 AND bakery_security_logs.year = 2021
AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute >= 15 AND bakery_security_logs.minute <= 25;

--Get names who left bakery during the 10 minutes after the theft using the license plate numbers

Select name
FROM people
WHERE license_plate = "5P2BI95" OR license_plate = "94KL13X" OR license_plate = "6P58WS2" OR license_plate = "4328GD8"
OR license_plate = "G412CB7" OR license_plate = "L93JTIZ" OR license_plate = "322W7JE" OR license_plate = "0NTHK55";

/* Vanessa, Barry, Iman, Sofia, Luca, Diana, Kelsey, Bruce */

--Find account numbers for people who left bakery

Select name, account_number
FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE people.name = "Vanessa" OR people.name = "Barry" OR people.name = "Iman" OR people.name = "Sofia" OR
people.name = "Luca" OR people.name = "Diana" OR people.name = "Kelsey" OR people.name = "Bruce";

--See if any of those account numbers made a withdrawel the morning of the theft

Select *
FROM atm_transactions
WHERE day = 28 AND month = 7 AND year = 2021 AND atm_location = "Leggett Street";

--Barry made no Withdrawel
--Get phone numbers for remaining perps

SELECT name, phone_number
FROM people
WHERE name = "Bruce" OR name = "Diana" OR name = "Iman" OR name = "Luca";

--Get phone records for around the theft time and see who the remaining perps called and when

Select *
FROM phone_calls
WHERE day = 28 AND month = 7 AND year = 2021 AND duration <= 60;

-- Diana and Bruce both made outgoing calls < 60 seconds
-- Find names of receivers of those phone calls

SELECT name
FROM people
WHERE phone_number = "(725) 555-3243" OR phone_number = "(375) 555-8161";

--Diana called Philip
--Bruce called Robin

--Find flights for 7/29/2021

SELECT *
FROM flights
WHERE day = 29 AND month = 7 AND year = 2021;

-- See if any of the perps are on the earliest flight

SELECT passport_number
FROM passengers
WHERE flight_id = 36;

--Remember info for perps and match to passport number on the flight

SELECT *
FROM people
WHERE name = "Bruce" OR name = "Diana";

--Find destination airport

SELECT city
FROM airports
WHERE id = 4;
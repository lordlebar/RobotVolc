Readme !!!!!

Place the directory in your Wamp, Lamp, Mamp please and run this code in Qt creator.

this project has been created to run on a volcanic exploration robot, you will have to create a database containing this :


file created by MySql in export of the blank database

-- phpMyAdmin SQL Dump
-- version 4.9.3
-- https://www.phpmyadmin.net/
--
-- Host: localhost:8889
-- Generation Time: Jul 18, 2022 at 11:17 PM
-- Server version: 5.7.26
-- PHP Version: 7.4.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

--
-- Database: `robotvolc`
--

-- --------------------------------------------------------

--
-- Table structure for table `campagnes`
--

CREATE TABLE `campagnes` (
  `idCAMPAGNES` int(11) NOT NULL,
  `pilote` varchar(45) NOT NULL,
  `site` varchar(45) NOT NULL,
  `Date_Heure` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `prelevements`
--

CREATE TABLE `prelevements` (
  `idPRELEVEMENTS` int(11) NOT NULL,
  `temperature` int(11) DEFAULT NULL,
  `mineraux` tinyint(4) DEFAULT NULL,
  `CAMPAGNES_idCAMPAGNES` int(11) NOT NULL,
  `WAYPOINTS_idWAYPOINTS` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `robotlive`
--

CREATE TABLE `robotlive` (
  `Longitude` float NOT NULL,
  `Latitude` float NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `robotlive`
--

INSERT INTO `robotlive` (`Longitude`, `Latitude`) VALUES
(0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `waypoints`
--

CREATE TABLE `waypoints` (
  `idWAYPOINTS` int(11) NOT NULL,
  `latitude` float DEFAULT NULL,
  `longitude` float DEFAULT NULL,
  `altitude` float DEFAULT NULL,
  `CAMPAGNES_idCAMPAGNES` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `campagnes`
--
ALTER TABLE `campagnes`
  ADD PRIMARY KEY (`idCAMPAGNES`);

--
-- Indexes for table `prelevements`
--
ALTER TABLE `prelevements`
  ADD PRIMARY KEY (`idPRELEVEMENTS`),
  ADD KEY `fk_PRELEVEMENTS_CAMPAGNES1_idx` (`CAMPAGNES_idCAMPAGNES`),
  ADD KEY `fk_PRELEVEMENTS_WAYPOINTS1_idx` (`WAYPOINTS_idWAYPOINTS`);

--
-- Indexes for table `waypoints`
--
ALTER TABLE `waypoints`
  ADD PRIMARY KEY (`idWAYPOINTS`),
  ADD KEY `fk_WAYPOINTS_CAMPAGNES_idx` (`CAMPAGNES_idCAMPAGNES`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `campagnes`
--
ALTER TABLE `campagnes`
  MODIFY `idCAMPAGNES` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `prelevements`
--
ALTER TABLE `prelevements`
  MODIFY `idPRELEVEMENTS` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `waypoints`
--
ALTER TABLE `waypoints`
  MODIFY `idWAYPOINTS` int(11) NOT NULL AUTO_INCREMENT;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `prelevements`
--
ALTER TABLE `prelevements`
  ADD CONSTRAINT `fk_PRELEVEMENTS_CAMPAGNES1` FOREIGN KEY (`CAMPAGNES_idCAMPAGNES`) REFERENCES `campagnes` (`idCAMPAGNES`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  ADD CONSTRAINT `fk_PRELEVEMENTS_WAYPOINTS1` FOREIGN KEY (`WAYPOINTS_idWAYPOINTS`) REFERENCES `waypoints` (`idWAYPOINTS`) ON DELETE NO ACTION ON UPDATE NO ACTION;

--
-- Constraints for table `waypoints`
--
ALTER TABLE `waypoints`
  ADD CONSTRAINT `fk_WAYPOINTS_CAMPAGNES` FOREIGN KEY (`CAMPAGNES_idCAMPAGNES`) REFERENCES `campagnes` (`idCAMPAGNES`) ON DELETE NO ACTION ON UPDATE NO ACTION;

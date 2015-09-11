/*
Navicat SQLite Data Transfer

Source Server         : mGet
Source Server Version : 30808
Source Host           : :0

Target Server Type    : SQLite
Target Server Version : 30808
File Encoding         : 65001

Date: 2015-06-24 19:51:07
*/

PRAGMA foreign_keys = OFF;

-- ----------------------------
-- Table structure for Queue
-- ----------------------------
DROP TABLE IF EXISTS main.Queue;
CREATE TABLE Queue (
QueueId  INTEGER NOT NULL,
Url  TEXT(100) NOT NULL,
FileSize  INTEGER,
DateCreated  TEXT(100) NOT NULL,
Status  INTEGER NOT NULL,
DateCompleted  TEXT(100),
PRIMARY KEY (QueueId ASC)
);

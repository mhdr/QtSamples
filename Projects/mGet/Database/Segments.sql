/*
Navicat SQLite Data Transfer

Source Server         : mGet
Source Server Version : 30808
Source Host           : :0

Target Server Type    : SQLite
Target Server Version : 30808
File Encoding         : 65001

Date: 2015-06-24 20:01:44
*/

PRAGMA foreign_keys = OFF;

-- ----------------------------
-- Table structure for Segments
-- ----------------------------
DROP TABLE IF EXISTS main.Segments;
CREATE TABLE Segments (
SegmentId  INTEGER NOT NULL,
QueueId  INTEGER NOT NULL,
FileName  TEXT(100),
Start  INTEGER NOT NULL,
End  INTEGER NOT NULL,
PRIMARY KEY (SegmentId ASC),
CONSTRAINT FK1 FOREIGN KEY (QueueId) REFERENCES Queue (QueueId)
);

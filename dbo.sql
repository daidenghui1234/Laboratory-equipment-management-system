/*
 Navicat Premium Data Transfer

 Source Server         : sqlserver
 Source Server Type    : SQL Server
 Source Server Version : 10001600
 Source Host           : localhost:1433
 Source Catalog        : test02
 Source Schema         : dbo

 Target Server Type    : SQL Server
 Target Server Version : 10001600
 File Encoding         : 65001

 Date: 17/12/2020 23:15:46
*/


-- ----------------------------
-- Table structure for device
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[device]') AND type IN ('U'))
	DROP TABLE [dbo].[device]
GO

CREATE TABLE [dbo].[device] (
  [id] int  IDENTITY(1,1) NOT NULL,
  [device_name] varchar(255) COLLATE Chinese_PRC_CI_AS  NOT NULL,
  [device_number] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [model_number] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [device_spec] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [device_price] real  NULL,
  [device_quantity] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [buy_date] datetime  NULL,
  [device_producer] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [device_purchaser] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [device_lot] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL
)
GO

ALTER TABLE [dbo].[device] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Records of device
-- ----------------------------
SET IDENTITY_INSERT [dbo].[device] ON
GO

INSERT INTO [dbo].[device] ([id], [device_name], [device_number], [model_number], [device_spec], [device_price], [device_quantity], [buy_date], [device_producer], [device_purchaser], [device_lot]) VALUES (N'12', N'联想', N'DESKTIP-UPKHG4Q', N'XiaoXin Ari 14ARR', N'RGEN2500', N'52.02', N'389', N'2020-12-16 00:00:00.000', N'德国进口', N'赵永乐', N'1')
GO

INSERT INTO [dbo].[device] ([id], [device_name], [device_number], [model_number], [device_spec], [device_price], [device_quantity], [buy_date], [device_producer], [device_purchaser], [device_lot]) VALUES (N'14', N'VR', N'OD-88', N'88-45-4', N'全套', N'1000', N'29', N'2016-01-01 00:00:00.000', N'美国VR厂', N'代登辉', N'2')
GO

SET IDENTITY_INSERT [dbo].[device] OFF
GO


-- ----------------------------
-- Table structure for device_copy1
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[device_copy1]') AND type IN ('U'))
	DROP TABLE [dbo].[device_copy1]
GO

CREATE TABLE [dbo].[device_copy1] (
  [id] int  IDENTITY(1,1) NOT NULL,
  [device_name] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [device_number] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [model_number] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [device_spec] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [device_price] real  NULL,
  [device_quantity] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [buy_date] datetime  NULL,
  [device_producer] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [device_purchaser] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [device_lot] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL
)
GO

ALTER TABLE [dbo].[device_copy1] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Records of device_copy1
-- ----------------------------
SET IDENTITY_INSERT [dbo].[device_copy1] ON
GO

INSERT INTO [dbo].[device_copy1] ([id], [device_name], [device_number], [model_number], [device_spec], [device_price], [device_quantity], [buy_date], [device_producer], [device_purchaser], [device_lot]) VALUES (N'12', N'联想', N'DESKTIP-UPKHG4Q', N'XiaoXin Ari 14ARR', N'RGEN2500', N'52.02', N'500', N'2020-12-16 00:00:00.000', N'德国进口', N'赵永乐', N'1')
GO

INSERT INTO [dbo].[device_copy1] ([id], [device_name], [device_number], [model_number], [device_spec], [device_price], [device_quantity], [buy_date], [device_producer], [device_purchaser], [device_lot]) VALUES (N'13', N'宏基', N'DESKTOP—H', N'8520', N'整机一台', N'50000', N'5', N'2020-12-16 00:00:00.000', N'宝鸡文理学院8号楼507', N'代登辉', N'2')
GO

INSERT INTO [dbo].[device_copy1] ([id], [device_name], [device_number], [model_number], [device_spec], [device_price], [device_quantity], [buy_date], [device_producer], [device_purchaser], [device_lot]) VALUES (N'14', N'VR', N'OD-88', N'88-45-4', N'全套', N'1000', N'5', N'2016-01-01 00:00:00.000', N'美国VR厂', N'代登辉', N'2')
GO

SET IDENTITY_INSERT [dbo].[device_copy1] OFF
GO


-- ----------------------------
-- Table structure for repair
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[repair]') AND type IN ('U'))
	DROP TABLE [dbo].[repair]
GO

CREATE TABLE [dbo].[repair] (
  [id] varchar(255) COLLATE Chinese_PRC_CI_AS  NOT NULL,
  [name] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [price] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [personliable] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [repairdept] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [number] int  NULL,
  [lot] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL
)
GO

ALTER TABLE [dbo].[repair] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Records of repair
-- ----------------------------
INSERT INTO [dbo].[repair] VALUES (N'2016102910', N'联想', N'555', N'代登辉', N'宝鸡', N'55', N'2')
GO

INSERT INTO [dbo].[repair] VALUES (N'2020202020', N'宏基', N'5000', N'代登辉', N'8号楼507', N'1', N'1')
GO

INSERT INTO [dbo].[repair] VALUES (N'2020617251', N'VR', N'500', N'代登辉', N'宝鸡', N'10', N'1')
GO


-- ----------------------------
-- Table structure for Scrap
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[Scrap]') AND type IN ('U'))
	DROP TABLE [dbo].[Scrap]
GO

CREATE TABLE [dbo].[Scrap] (
  [id] int  IDENTITY(1,1) NOT NULL,
  [name] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [num] int  NULL,
  [batch] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL,
  [data] datetime  NULL,
  [tip] varchar(255) COLLATE Chinese_PRC_CI_AS  NULL
)
GO

ALTER TABLE [dbo].[Scrap] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Records of Scrap
-- ----------------------------
SET IDENTITY_INSERT [dbo].[Scrap] ON
GO

INSERT INTO [dbo].[Scrap] ([id], [name], [num], [batch], [data], [tip]) VALUES (N'1', N'联想', N'5', N'2-5', N'2020-12-17 20:51:07.000', N'电路板老化')
GO

INSERT INTO [dbo].[Scrap] ([id], [name], [num], [batch], [data], [tip]) VALUES (N'2', N'宏基', N'5', N'1-2', N'2020-12-10 00:00:00.000', N'报废')
GO

INSERT INTO [dbo].[Scrap] ([id], [name], [num], [batch], [data], [tip]) VALUES (N'3', N'联想', N'5', N'1-1-1', N'2020-12-10 00:00:00.000', N'电路老化')
GO

SET IDENTITY_INSERT [dbo].[Scrap] OFF
GO


-- ----------------------------
-- Table structure for user
-- ----------------------------
IF EXISTS (SELECT * FROM sys.all_objects WHERE object_id = OBJECT_ID(N'[dbo].[user]') AND type IN ('U'))
	DROP TABLE [dbo].[user]
GO

CREATE TABLE [dbo].[user] (
  [id] int  IDENTITY(1,1) NOT NULL,
  [name] varchar(255) COLLATE Chinese_PRC_CI_AS  NOT NULL,
  [password] varchar(255) COLLATE Chinese_PRC_CI_AS  NOT NULL
)
GO

ALTER TABLE [dbo].[user] SET (LOCK_ESCALATION = TABLE)
GO


-- ----------------------------
-- Records of user
-- ----------------------------
SET IDENTITY_INSERT [dbo].[user] ON
GO

INSERT INTO [dbo].[user] ([id], [name], [password]) VALUES (N'1', N'admin', N'admin')
GO

INSERT INTO [dbo].[user] ([id], [name], [password]) VALUES (N'2', N'dai', N'dai')
GO

INSERT INTO [dbo].[user] ([id], [name], [password]) VALUES (N'3', N'', N'')
GO

SET IDENTITY_INSERT [dbo].[user] OFF
GO


-- ----------------------------
-- Auto increment value for device
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[device]', RESEED, 14)
GO


-- ----------------------------
-- Triggers structure for table device
-- ----------------------------
CREATE TRIGGER [dbo].[tgr_in_update]
ON [dbo].[device]
WITH EXECUTE AS CALLER
FOR UPDATE
AS
DELETE from [device] where device.device_quantity < 1
GO


-- ----------------------------
-- Primary Key structure for table device
-- ----------------------------
ALTER TABLE [dbo].[device] ADD CONSTRAINT [PK__device__3213E83F03317E3D] PRIMARY KEY CLUSTERED ([id], [device_name])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for device_copy1
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[device_copy1]', RESEED, 14)
GO


-- ----------------------------
-- Primary Key structure for table device_copy1
-- ----------------------------
ALTER TABLE [dbo].[device_copy1] ADD CONSTRAINT [PK__device__3213E83F03317E3D_copy1] PRIMARY KEY CLUSTERED ([id])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Triggers structure for table repair
-- ----------------------------
CREATE TRIGGER [dbo].[tgr_in_repair_update]
ON [dbo].[repair]
WITH EXECUTE AS CALLER
FOR UPDATE
AS
DELETE from [repair] where repair.number < 1
GO


-- ----------------------------
-- Primary Key structure for table repair
-- ----------------------------
ALTER TABLE [dbo].[repair] ADD CONSTRAINT [PK__repair__3213E83F0CBAE877] PRIMARY KEY CLUSTERED ([id])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


-- ----------------------------
-- Auto increment value for Scrap
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[Scrap]', RESEED, 3)
GO


-- ----------------------------
-- Auto increment value for user
-- ----------------------------
DBCC CHECKIDENT ('[dbo].[user]', RESEED, 3)
GO


-- ----------------------------
-- Primary Key structure for table user
-- ----------------------------
ALTER TABLE [dbo].[user] ADD CONSTRAINT [PK__user__3213E83F7F60ED59] PRIMARY KEY CLUSTERED ([id])
WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON)  
ON [PRIMARY]
GO


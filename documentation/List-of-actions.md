Generated Thu Mar 15 08:45:28 2012 by make_actions_html
<div align="center">
<h1>List of Actions</h1>
</div>
<a name="ActionCategories"></a>
<h2>Action Categories</h2>
<a name="ActionCategories"></a>

&nbsp;

<a name="ActionCategories"></a>

There is a large library of actions available for scheduling as events.
Additionally, all of these actions can be used within analyze scripts.
Below you will find a listing of the high level groupings of these
actions, along with detailed sections for each them.

<dl><dt><a href="#PrintActions">Print</a></dt><dd>Print actions are the primary way of saving data from an Avida experiments.</dd><dt><a href="#PopulationActions">Population</a></dt><dd>Population actions modify the state of the population, and will actually change the course of the run.</dd><dt><a href="#EnvironmentActions">Environment</a></dt><dd>Actions that allow user to change properties of the environment, including resources.</dd><dt><a href="#SaveLoadActions">Save and Load</a></dt><dd>Actions that allow for saving and loading large data sets, such as full populations.</dd><dt><a href="#LandscapeActions">Landscape Analysis</a></dt><dd>Actions that use data from the current state of Avida, process it and then output the results.</dd><dt><a href="#DriverActions">Driver</a></dt><dd>Actions that allow user to control program execution, including experiment termination.</dd></dl>For a brief overview of writing a new action, please see <a href="#CreateAction">Creating an Action</a> below.

&nbsp;
<h2>Alphabetical Listing of Available Actions</h2>
<table>
<tbody>
<tr>
<td>
<a href="#AnalyzeLandscape">AnalyzeLandscape</a>
<a href="#AnalyzePopulation">AnalyzePopulation</a>
<a href="#AssignRandomCellData">AssignRandomCellData</a>
<a href="#AttackDen">AttackDen</a>
<a href="#AvidianConjugation">AvidianConjugation</a>
<a href="#CalcConsensus">CalcConsensus</a>
<a href="#ChangeEnvironment">ChangeEnvironment</a>
<a href="#CompeteDemes">CompeteDemes</a>
<a href="#CompeteDemes_AttackKillAndEnergyConserve">CompeteDemes_AttackKillAndEnergyConserve</a>
<a href="#CompeteDemesByEnergyDistribution">CompeteDemesByEnergyDistribution</a>
<a href="#CompeteDemesByNetwork">CompeteDemesByNetwork</a>
<a href="#CompeteDemesByTaskCount">CompeteDemesByTaskCount</a>
<a href="#CompeteDemesByTaskCountAndEfficiency">CompeteDemesByTaskCountAndEfficiency</a>
<a href="#CompeteOrganisms">CompeteOrganisms</a>
<a href="#ConnectCells">ConnectCells</a>
<a href="#CopyDeme">CopyDeme</a>
<a href="#CountMultipleOpinions">CountMultipleOpinions</a>
<a href="#CountOpinions">CountOpinions</a>
<a href="#DecayPoints">DecayPoints</a>
<a href="#DelayedDemeEvent">DelayedDemeEvent</a>
<a href="#DelayedDemeEventsPerSlots">DelayedDemeEventsPerSlots</a>
<a href="#DeletionLandscape">DeletionLandscape</a>
<a href="#DemeBalanceTwoTasks">DemeBalanceTwoTasks</a>
<a href="#DemeReactionDiversity">DemeReactionDiversity</a>
<a href="#DemeResourceThresholdPredicate">DemeResourceThresholdPredicate</a>
<a href="#Desynchronization">Desynchronization</a>
<a href="#DiffuseHGTGenomeFragments">DiffuseHGTGenomeFragments</a>
<a href="#DisconnectCells">DisconnectCells</a>
<a href="#DistributeData">DistributeData</a>
<a href="#DistributeDataCheaply">DistributeDataCheaply</a>
<a href="#DistributeDataEfficiently">DistributeDataEfficiently</a>
<a href="#DivideDemes">DivideDemes</a>
<a href="#DumpCellDataGrid">DumpCellDataGrid</a>
<a href="#DumpClassificationIDGrid">DumpClassificationIDGrid</a>
<a href="#DumpDonorGrid">DumpDonorGrid</a>
<a href="#DumpEnergyGrid">DumpEnergyGrid</a>
<a href="#DumpExecutionRatioGrid">DumpExecutionRatioGrid</a>
<a href="#DumpFitnessGrid">DumpFitnessGrid</a>
<a href="#DumpGenomeLengthGrid">DumpGenomeLengthGrid</a>
<a href="#DumpGenotypeColorGrid">DumpGenotypeColorGrid</a>
<a href="#DumpGenotypeGrid">DumpGenotypeGrid</a>
<a href="#DumpHostTaskGrid">DumpHostTaskGrid</a>
<a href="#DumpIDGrid">DumpIDGrid</a>
<a href="#DumpLandscape">DumpLandscape</a>
<a href="#DumpLastTaskGrid">DumpLastTaskGrid</a>
<a href="#DumpMaxResGrid">DumpMaxResGrid</a>
<a href="#DumpMemory">DumpMemory</a>
<a href="#DumpParasiteGenotypeGrid">DumpParasiteGenotypeGrid</a>
<a href="#DumpParasiteTaskGrid">DumpParasiteTaskGrid</a>
<a href="#DumpParasiteVirulenceGrid">DumpParasiteVirulenceGrid</a>
<a href="#DumpPhenotypeIDGrid">DumpPhenotypeIDGrid</a>
<a href="#DumpReactionGrid">DumpReactionGrid</a>
<a href="#DumpReceiverGrid">DumpReceiverGrid</a>
<a href="#DumpSleepGrid">DumpSleepGrid</a>
<a href="#DumpTargetGrid">DumpTargetGrid</a>
<a href="#DumpTaskGrid">DumpTaskGrid</a>
<a href="#DumpVitalityGrid">DumpVitalityGrid</a>
<a href="#Echo">Echo</a>
<a href="#Exit">Exit</a>
<a href="#ExitAveGeneration">ExitAveGeneration</a>
<a href="#ExitAveLineageLabelGreater">ExitAveLineageLabelGreater</a>
<a href="#ExitAveLineageLabelLess">ExitAveLineageLabelLess</a>
<a href="#ExitDemeReplications">ExitDemeReplications</a>
<a href="#ExitElapsedTime">ExitElapsedTime</a>
<a href="#Flash">Flash</a>
<a href="#FlushTopNavTrace">FlushTopNavTrace</a>
<a href="#FullLandscape">FullLandscape</a>
<a href="#HillClimb">HillClimb</a>
<a href="#Inject">Inject</a>
<a href="#InjectAll">InjectAll</a>
<a href="#InjectAllRandomRepro">InjectAllRandomRepro</a>
<a href="#InjectCanvas">InjectCanvas</a>
<a href="#InjectDemes">InjectDemes</a>
<a href="#InjectDemesFromNest">InjectDemesFromNest</a>
<a href="#InjectDemesRandom">InjectDemesRandom</a>
<a href="#InjectGroup">InjectGroup</a>
<a href="#InjectModuloDemes">InjectModuloDemes</a>
<a href="#InjectParasite">InjectParasite</a>
<a href="#InjectParasitePair">InjectParasitePair</a>
<a href="#InjectRandom">InjectRandom</a>
<a href="#InjectRange">InjectRange</a>
<a href="#InjectResource">InjectResource</a>
<a href="#InjectScaledResource">InjectScaledResource</a>
<a href="#InjectSequence">InjectSequence</a>
<a href="#InjectSequenceWDivMutRate">InjectSequenceWDivMutRate</a>
<a href="#InsertionLandscape">InsertionLandscape</a>
<a href="#IteratedConsensus">IteratedConsensus</a>
<a href="#JoinGridCol">JoinGridCol</a>
<a href="#JoinGridRow">JoinGridRow</a>
<a href="#KillFractionInSequence">KillFractionInSequence</a>
<a href="#KillFractionInSequence_PopLimit">KillFractionInSequence_PopLimit</a>
<a href="#KillInstLimit">KillInstLimit</a>
<a href="#KillInstPair">KillInstPair</a>
<a href="#KillMeanBelowThresholdPaintable">KillMeanBelowThresholdPaintable</a>
<a href="#KillNBelowResourceThreshold">KillNBelowResourceThreshold</a>
<a href="#KillProb">KillProb</a>
<a href="#KillRate">KillRate</a>
<a href="#KillRectangle">KillRectangle</a>
<a href="#KillWithinRadiusBelowResourceThreshold">KillWithinRadiusBelowResourceThreshold</a>
<a href="#KillWithinRadiusBelowResourceThresholdTestAll">KillWithinRadiusBelowResourceThresholdTestAll</a>
<a href="#KillWithinRadiusMeanBelowResourceThreshold">KillWithinRadiusMeanBelowResourceThreshold</a>
<a href="#LoadPopulation">LoadPopulation</a>
<a href="#MeasureDemeNetworks">MeasureDemeNetworks</a>
<a href="#MergeResourceAcrossDemes">MergeResourceAcrossDemes</a>
<a href="#MixPopulation">MixPopulation</a>
<a href="#ModMutProb">ModMutProb</a>
<a href="#MutationalNeighborhood">MutationalNeighborhood</a>
<a href="#NewTrial">NewTrial</a>
<a href="#OutflowScaledResource">OutflowScaledResource</a>
<a href="#PairTestLandscape">PairTestLandscape</a>
<a href="#Pause">Pause</a>
<a href="#PhenotypeMatch">PhenotypeMatch</a>
<a href="#PrecalcLandscape">PrecalcLandscape</a>
<a href="#Pred_DemeEventMoveBetweenTargets">Pred_DemeEventMoveBetweenTargets</a>
<a href="#Pred_DemeEventMoveCenter">Pred_DemeEventMoveCenter</a>
<a href="#Pred_DemeEventNUniqueIndividualsMovedIntoTarget">Pred_DemeEventNUniqueIndividualsMovedIntoTarget</a>
<a href="#PredictNuLandscape">PredictNuLandscape</a>
<a href="#PredictWLandscape">PredictWLandscape</a>
</td>
<td>
<a href="#PrintAgePolyethismData">PrintAgePolyethismData</a><br>
<a href="#PrintAveNumTasks">PrintAveNumTasks</a><br>
<a href="#PrintAverageData">PrintAverageData</a><br>
<a href="#PrintAvgDemeTasksExeData">PrintAvgDemeTasksExeData</a><br>
<a href="#PrintAvgTreatableDemeTasksExeData">PrintAvgTreatableDemeTasksExeData</a><br>
<a href="#PrintAvgUntreatableDemeTasksExeData">PrintAvgUntreatableDemeTasksExeData</a><br>
<a href="#PrintBirthChamber">PrintBirthChamber</a><br>
<a href="#PrintBirthChamberMatingTypeHistogram">PrintBirthChamberMatingTypeHistogram</a><br>
<a href="#PrintCCladeCounts">PrintCCladeCounts</a><br>
<a href="#PrintCCladeFitnessHistogram">PrintCCladeFitnessHistogram</a><br>
<a href="#PrintCCladeRelativeFitnessHistogram">PrintCCladeRelativeFitnessHistogram</a><br>
<a href="#PrintCellData">PrintCellData</a><br>
<a href="#PrintCellVisitsData">PrintCellVisitsData</a><br>
<a href="#PrintCompetitionData">PrintCompetitionData</a><br>
<a href="#PrintConsensusData">PrintConsensusData</a><br>
<a href="#PrintCountData">PrintCountData</a><br>
<a href="#PrintCurrentMeanDemeDensity">PrintCurrentMeanDemeDensity</a><br>
<a href="#PrintCurrentOpinions">PrintCurrentOpinions</a><br>
<a href="#PrintCurrentReactionData">PrintCurrentReactionData</a><br>
<a href="#PrintCurrentReactionRewardData">PrintCurrentReactionRewardData</a><br>
<a href="#PrintCurrentTaskCounts">PrintCurrentTaskCounts</a><br>
<a href="#PrintData">PrintData</a><br>
<a href="#PrintDebug">PrintDebug</a><br>
<a href="#PrintDemeAllStats">PrintDemeAllStats</a><br>
<a href="#PrintDemeAverageData">PrintDemeAverageData</a><br>
<a href="#PrintDemeCompetitionData">PrintDemeCompetitionData</a><br>
<a href="#PrintDemeCurrentTaskExeData">PrintDemeCurrentTaskExeData</a><br>
<a href="#PrintDemeDonorStats">PrintDemeDonorStats</a><br>
<a href="#PrintDemeEnergyDistributionStats">PrintDemeEnergyDistributionStats</a><br>
<a href="#PrintDemeEnergySharingStats">PrintDemeEnergySharingStats</a><br>
<a href="#PrintDemeFoundersData">PrintDemeFoundersData</a><br>
<a href="#PrintDemeGermlineSequestration">PrintDemeGermlineSequestration</a><br>
<a href="#PrintDemeGlobalResources">PrintDemeGlobalResources</a><br>
<a href="#PrintDemeMigrationSuicidePoints">PrintDemeMigrationSuicidePoints</a><br>
<a href="#PrintDemeNetworkData">PrintDemeNetworkData</a><br>
<a href="#PrintDemeNetworkTopology">PrintDemeNetworkTopology</a><br>
<a href="#PrintDemeOrgReactionData">PrintDemeOrgReactionData</a><br>
<a href="#PrintDemeOrgTasksData">PrintDemeOrgTasksData</a><br>
<a href="#PrintDemeOrgTasksExeData">PrintDemeOrgTasksExeData</a><br>
<a href="#PrintDemeReactionData">PrintDemeReactionData</a><br>
<a href="#PrintDemeReactionDiversityReplicationData">PrintDemeReactionDiversityReplicationData</a><br>
<a href="#PrintDemeReplicationData">PrintDemeReplicationData</a><br>
<a href="#PrintDemeResourceStats">PrintDemeResourceStats</a><br>
<a href="#PrintDemeResourceThresholdPredicate">PrintDemeResourceThresholdPredicate</a><br>
<a href="#PrintDemeSpacialEnergyStats">PrintDemeSpacialEnergyStats</a><br>
<a href="#PrintDemeSpacialSleepStats">PrintDemeSpacialSleepStats</a><br>
<a href="#PrintDemeStats">PrintDemeStats</a><br>
<a href="#PrintDemesTotalAvgEnergy">PrintDemesTotalAvgEnergy</a><br>
<a href="#PrintDemeTasksData">PrintDemeTasksData</a><br>
<a href="#PrintDemeTasksExeData">PrintDemeTasksExeData</a><br>
<a href="#PrintDemeTestamentStats">PrintDemeTestamentStats</a><br>
<a href="#PrintDemeTreatableCount">PrintDemeTreatableCount</a><br>
<a href="#PrintDemeTreatableReplicationData">PrintDemeTreatableReplicationData</a><br>
<a href="#PrintDemeUntreatableReplicationData">PrintDemeUntreatableReplicationData</a><br>
<a href="#PrintDepthHistogram">PrintDepthHistogram</a><br>
<a href="#PrintDetailedFitnessData">PrintDetailedFitnessData</a><br>
<a href="#PrintDetailedSynchronizationData">PrintDetailedSynchronizationData</a><br>
<a href="#PrintDirectReciprocityData">PrintDirectReciprocityData</a><br>
<a href="#PrintDivideMutData">PrintDivideMutData</a><br>
<a href="#PrintDominantData">PrintDominantData</a><br>
<a href="#PrintDominantForagerGenotypes">PrintDominantForagerGenotypes</a><br>
<a href="#PrintDominantGenotype">PrintDominantGenotype</a><br>
<a href="#PrintDominantGroupGenotypes">PrintDominantGroupGenotypes</a><br>
<a href="#PrintDonationStats">PrintDonationStats</a><br>
<a href="#PrintDynamicMaxMinData">PrintDynamicMaxMinData</a><br>
<a href="#PrintEditDistance">PrintEditDistance</a><br>
<a href="#PrintErrorData">PrintErrorData</a><br>
<a href="#PrintExtendedTimeData">PrintExtendedTimeData</a><br>
<a href="#PrintFemaleMatePreferenceData">PrintFemaleMatePreferenceData</a><br>
<a href="#PrintFlowRateTuples">PrintFlowRateTuples</a><br>
<a href="#PrintGeneticDistanceData">PrintGeneticDistanceData</a><br>
<a href="#PrintGenomicSiteEntropy">PrintGenomicSiteEntropy</a><br>
<a href="#PrintGenotypeAbundanceHistogram">PrintGenotypeAbundanceHistogram</a><br>
<a href="#PrintGermlineData">PrintGermlineData</a><br>
<a href="#PrintGroupIds">PrintGroupIds</a><br>
<a href="#PrintGroupsFormedData">PrintGroupsFormedData</a><br>
<a href="#PrintGroupTolerance">PrintGroupTolerance</a><br>
<a href="#PrintHGTData">PrintHGTData</a><br>
<a href="#PrintHostDepthHistogram">PrintHostDepthHistogram</a><br>
<a href="#PrintHostPhenotypeData">PrintHostPhenotypeData</a><br>
<a href="#PrintHostTasksData">PrintHostTasksData</a><br>
<a href="#PrintInstructionAbundanceHistogram">PrintInstructionAbundanceHistogram</a><br>
<a href="#PrintInstructionData">PrintInstructionData</a><br>
<a href="#PrintInternalTasksData">PrintInternalTasksData</a><br>
<a href="#PrintInternalTasksQualData">PrintInternalTasksQualData</a><br>
<a href="#PrintInterruptData">PrintInterruptData</a><br>
<a href="#PrintLineageCounts">PrintLineageCounts</a><br>
<a href="#PrintLineageTotals">PrintLineageTotals</a><br>
<a href="#PrintLogFitnessHistogram">PrintLogFitnessHistogram</a><br>
<a href="#PrintMarketData">PrintMarketData</a><br>
<a href="#PrintMatingDisplayData">PrintMatingDisplayData</a><br>
<a href="#PrintMatingTypeHistogram">PrintMatingTypeHistogram</a><br>
<a href="#PrintMessageData">PrintMessageData</a><br>
<a href="#PrintMessageLog">PrintMessageLog</a><br>
<a href="#PrintMigrationData">PrintMigrationData</a><br>
<a href="#PrintMiniTraces">PrintMiniTraces</a><br>
<a href="#PrintMicroTraces">PrintMicroTraces</a><br>
<a href="#PrintMultiProcessData">PrintMultiProcessData</a><br>
<a href="#PrintMutationRateData">PrintMutationRateData</a><br>
<a href="#PrintNewReactionData">PrintNewReactionData</a><br>
<a href="#PrintNewTasksData">PrintNewTasksData</a><br>
<a href="#PrintNewTasksDataPlus">PrintNewTasksDataPlus</a><br>
<a href="#PrintNumOrgsInDeme">PrintNumOrgsInDeme</a><br>
<a href="#PrintNumOrgsKilledData">PrintNumOrgsKilledData</a><br>
<a href="#PrintOpinionsSetPerDeme">PrintOpinionsSetPerDeme</a><br>
<a href="#PrintOrganismLocation">PrintOrganismLocation</a><br>
<a href="#PrintParasiteData">PrintParasiteData</a><br>
<a href="#PrintParasiteDepthHistogram">PrintParasiteDepthHistogram</a><br>
<a href="#PrintParasitePhenotypeData">PrintParasitePhenotypeData</a><br>
<a href="#PrintParasiteTasksData">PrintParasiteTasksData</a><br>
<a href="#PrintPerDemeGenPerFounderData">PrintPerDemeGenPerFounderData</a><br>
<a href="#PrintPerDemeReactionData">PrintPerDemeReactionData</a><br>
<a href="#PrintPerDemeTasksData">PrintPerDemeTasksData</a><br>
<a href="#PrintPerDemeTasksExeData">PrintPerDemeTasksExeData</a><br>
<a href="#PrintPhenotypeData">PrintPhenotypeData</a><br>
<a href="#PrintPhenotypeStatus">PrintPhenotypeStatus</a><br>
<a href="#PrintPhenotypicPlasticity">PrintPhenotypicPlasticity</a><br>
</td>
<td>
<a href="#PrintPlasticGenotypeSummary">PrintPlasticGenotypeSummary</a><br>
<a href="#PrintPopulationDistanceData">PrintPopulationDistanceData</a><br>
<a href="#PrintPredatorAverageData">PrintPredatorAverageData</a><br>
<a href="#PrintPredatorErrorData">PrintPredatorErrorData</a><br>
<a href="#PrintPredatorInstructionData">PrintPredatorInstructionData</a><br>
<a href="#PrintPredatorVarianceData">PrintPredatorVarianceData</a><br>
<a href="#PrintMinPreyFailedAttacks">PrintMinPreyFailedAttacks</a><br>
<a href="#PrintPredicatedMessages">PrintPredicatedMessages</a><br>
<a href="#PrintPreyAverageData">PrintPreyAverageData</a><br>
<a href="#PrintPreyErrorData">PrintPreyErrorData</a><br>
<a href="#PrintPreyInstructionData">PrintPreyInstructionData</a><br>
<a href="#PrintPreyVarianceData">PrintPreyVarianceData</a><br>
<a href="#PrintProfilingData">PrintProfilingData</a><br>
<a href="#PrintReactionData">PrintReactionData</a><br>
<a href="#PrintReactionExeData">PrintReactionExeData</a><br>
<a href="#PrintReactionRewardData">PrintReactionRewardData</a><br>
<a href="#PrintRelativeFitnessHistogram">PrintRelativeFitnessHistogram</a><br>
<a href="#PrintReproData">PrintReproData</a><br>
<a href="#PrintReputationData">PrintReputationData</a><br>
<a href="#PrintResourceData">PrintResourceData</a><br>
<a href="#PrintSenseData">PrintSenseData</a><br>
<a href="#PrintSenseExeData">PrintSenseExeData</a><br>
<a href="#PrintShadedAltruists">PrintShadedAltruists</a><br>
<a href="#PrintSimpleConsensusData">PrintSimpleConsensusData</a><br>
<a href="#PrintSleepData">PrintSleepData</a><br>
<a href="#PrintSpeciesAbundanceHistogram">PrintSpeciesAbundanceHistogram</a><br>
<a href="#PrintStatsData">PrintStatsData</a><br>
<a href="#PrintStringMatchData">PrintStringMatchData</a><br>
<a href="#PrintSuccessfulMates">PrintSuccessfulMates</a><br>
<a href="#PrintSynchronizationData">PrintSynchronizationData</a><br>
<a href="#PrintTargets">PrintTargets</a><br>
<a href="#PrintTaskProbHistogram">PrintTaskProbHistogram</a><br>
<a href="#PrintTasksData">PrintTasksData</a><br>
<a href="#PrintTasksExeData">PrintTasksExeData</a><br>
<a href="#PrintTaskSnapshot">PrintTaskSnapshot</a><br>
<a href="#PrintTasksQualData">PrintTasksQualData</a><br>
<a href="#PrintThreadsData">PrintThreadsData</a><br>
<a href="#PrintTimeData">PrintTimeData</a><br>
<a href="#PrintToleranceData">PrintToleranceData</a><br>
<a href="#PrintToleranceInstructionData">PrintToleranceInstructionData</a><br>
<a href="#PrintTopNavTrace">PrintTopNavTrace</a><br>
<a href="#PrintTotalsData">PrintTotalsData</a><br>
<a href="#PrintVarianceData">PrintVarianceData</a><br>
<a href="#PrintViableTasksData">PrintViableTasksData</a><br>
<a href="#PrintWinningDeme">PrintWinningDeme</a><br>
<a href="#RandomLandscape">RandomLandscape</a><br>
<a href="#RemovePredators">RemovePredators</a><br>
<a href="#ReplaceFromGermline">ReplaceFromGermline</a><br>
<a href="#ReplicateDemes">ReplicateDemes</a><br>
<a href="#ResetDemes">ResetDemes</a><br>
<a href="#SampleLandscape">SampleLandscape</a><br>
<a href="#SaveDemeFounders">SaveDemeFounders</a><br>
<a href="#SaveFlameData">SaveFlameData</a><br>
<a href="#SavePopulation">SavePopulation</a><br>
<a href="#SerialTransfer">SerialTransfer</a><br>
<a href="#SetCellResource">SetCellResource</a><br>
<a href="#SetConfig">SetConfig</a><br>
<a href="#SetDemeResource">SetDemeResource</a><br>
<a href="#SetDemeResourceInflow">SetDemeResourceInflow</a><br>
<a href="#SetDemeResourceOutflow">SetDemeResourceOutflow</a><br>
<a href="#SetEnvironmentInputs">SetEnvironmentInputs</a><br>
<a href="#SetEnvironmentRandomMask">SetEnvironmentRandomMask</a><br>
<a href="#SetFracDemeTreatable">SetFracDemeTreatable</a><br>
<a href="#SetGradientResource">SetGradientResource</a><br>
<a href="#SetGradientInflow">SetGradientInflow</a><br>
<a href="#SetGradientOutflow">SetGradientOutflow</a><br>
<a href="#SetGradientConeInflow">SetGradientConeInflow</a><br>
<a href="#SetGradientConeOutflow">SetGradientConeOutflow</a><br>
<a href="#SetGradientPlatInflow">SetGradientPlatInflow</a><br>
<a href="#SetGradientPlatOutflow">SetGradientPlatOutflow</a><br>
<a href="#SetGradPlatVarInflow">SetGradPlatVarInflow</a><br>
<a href="#SetMigrationRate">SetMigrationRate</a><br>
<a href="#SetMutProb">SetMutProb</a><br>
<a href="#SetNumInstBefore0Energy">SetNumInstBefore0Energy</a><br>
<a href="#SetOptimizeMinMax">SetOptimizeMinMax</a><br>
<a href="#SetPeriodicResource">SetPeriodicResource</a><br>
<a href="#SetPopCapEnforcement">SetPopCapEnforcement</a><br>
<a href="#SetPredatoryResource">SetPredatoryResource</a><br>
<a href="#SetReactionInst">SetReactionInst</a><br>
<a href="#SetReactionMaxTaskCount">SetReactionMaxTaskCount</a><br>
<a href="#SetReactionMinTaskCount">SetReactionMinTaskCount</a><br>
<a href="#SetReactionTask">SetReactionTask</a><br>
<a href="#SetReactionValue">SetReactionValue</a><br>
<a href="#SetReactionValueMult">SetReactionValueMult</a><br>
<a href="#SetResource">SetResource</a><br>
<a href="#SetResourceInflow">SetResourceInflow</a><br>
<a href="#SetResourceOutflow">SetResourceOutflow</a><br>
<a href="#SetSeasonalResource">SetSeasonalResource</a><br>
<a href="#SetSeasonalResource10Kyears_1To_1">SetSeasonalResource10Kyears_1To_1</a><br>
<a href="#SetSeasonalResource1Kyears_1To_1">SetSeasonalResource1Kyears_1To_1</a><br>
<a href="#SetTaskArgDouble">SetTaskArgDouble</a><br>
<a href="#SetTaskArgInt">SetTaskArgInt</a><br>
<a href="#SetTaskArgString">SetTaskArgString</a><br>
<a href="#SetVerbose">SetVerbose</a><br>
<a href="#SeverGridCol">SeverGridCol</a><br>
<a href="#SeverGridRow">SeverGridRow</a><br>
<a href="#StopFastForward">StopFastForward</a><br>
<a href="#SwapCells">SwapCells</a><br>
<a href="#SwapRandomCells">SwapRandomCells</a><br>
<a href="#Synchronization">Synchronization</a><br>
<a href="#TestDominant">TestDominant</a><br>
<a href="#TherapyDecayDemeResource">TherapyDecayDemeResource</a><br>
<a href="#TherapyStructuralNumInst">TherapyStructuralNumInst</a><br>
<a href="#TherapyStructuralRatioDistBetweenNearest">TherapyStructuralRatioDistBetweenNearest</a><br>
<a href="#ToggleFitnessValley">ToggleFitnessValley</a><br>
<a href="#ToggleRewardInstruction">ToggleRewardInstruction</a><br>
<a href="#TrackAllMessages">TrackAllMessages</a><br>
<a href="#UnitFitness">UnitFitness</a><br>
<a href="#VERBOSE">VERBOSE</a><br>
<a href="#ZeroMuts">ZeroMuts</a><br>
<a href="#ZeroResources">ZeroResources</a><br>
</td>
</tr>
</tbody>
</table>
&nbsp;
<h2><a name="DriverActions"></a>Driver Actions</h2>
These actions control the driver object responsible for executing the current run.
<ul>
	<li><strong><a name="Exit"></a>Exit</strong>
<em>No Arguments</em>Unconditionally terminate the current run.</li>
	<li><strong><a name="ExitAveGeneration"></a>ExitAveGeneration</strong>
<em>&lt;double generation&gt;</em></li>
	<li><strong><a name="ExitAveLineageLabelGreater"></a>ExitAveLineageLabelGreater</strong>
<em>&lt;double threshold&gt;</em>Halts the run if the current average lineage label is larger
than <span class="cmdarg">threshold</span>.</li>
	<li><strong><a name="ExitAveLineageLabelLess"></a>ExitAveLineageLabelLess</strong>
<em>&lt;double threshold&gt;</em>Halts the run if the current average lineage label is smaller
than <span class="cmdarg">threshold</span>.</li>
	<li><strong><a name="ExitDemeReplications"></a>ExitDemeReplications</strong></li>
	<li><strong><a name="ExitElapsedTime"></a>ExitElapsedTime</strong>
<em>&lt;int elapsed time [seconds]&gt;</em></li>
	<li><strong><a name="Pause"></a>Pause</strong>
<em>No Arguments</em></li>
	<li><strong><a name="StopFastForward"></a>StopFastForward</strong>
<em>none</em></li>
</ul>
&nbsp;
<h2><a name="EnvironmentActions"></a>Environment Actions</h2>
Events that allow user to change environment properties, such as resources
and reaction parameters.
<ul>
	<li><strong><a name="ChangeEnvironment"></a>ChangeEnvironment</strong>
<em>&lt;string env_string&gt;</em>Action designed to read in and process a line formatted as if it were in the
<a href="environment.html">environment</a> file. This will change
environmental settings on the fly. <strong>You should create all resources and
reactions in the environment file</strong> and only use this file to change these
resources and reactions.  Also, note that this action does not replace reactions already in the environment that share the same name as the argument given to ChangeEnvironment; it simply adds another reaction with the same name.</li>
	<li><strong><a name="DelayedDemeEvent"></a>DelayedDemeEvent</strong>
<em>&lt;int x1&gt; &lt;int y1&gt; &lt;int x2&gt; &lt;int y2&gt; &lt;int delay&gt; &lt;int duration&gt; &lt;bool static_position&gt; &lt;int total_events&gt;</em></li>
	<li><strong><a name="DelayedDemeEventsPerSlots"></a>DelayedDemeEventsPerSlots</strong>
<em>&lt;int x1&gt; &lt;int y1&gt; &lt;int x2&gt; &lt;int y2&gt; &lt;int delay&gt; &lt;int duration&gt; &lt;bool static_position&gt; &lt;int total_slots_per_deme&gt; &lt;int total_events_per_slot_max&gt; &lt;int total_events_per_slot_min&gt; &lt;int tolal_event_flow_levels&gt;</em></li>
	<li><strong><a name="InjectResource"></a>InjectResource</strong>
<em>&lt;string res_name&gt; &lt;double res_count&gt;</em>Inject (add) a specified amount of a specified resource.
<span class="cmdarg">res_name</span> must already exist as
a resource in environment file.</li>
	<li><strong><a name="InjectScaledResource"></a>InjectScaledResource</strong>
<em>&lt;string res_name&gt; &lt;double res_count&gt;</em></li>
	<li><strong><a name="MergeResourceAcrossDemes"></a>MergeResourceAcrossDemes</strong>
<em>&lt;string deme_res_name&gt; &lt;string global_res_name&gt;</em></li>
	<li><strong><a name="OutflowScaledResource"></a>OutflowScaledResource</strong>
<em>&lt;string res_name&gt; &lt;double res_percent&gt;</em></li>
	<li><strong><a name="SetCellResource"></a>SetCellResource</strong>
<em>&lt;int cell_id&gt; &lt;string res_name&gt; &lt;double res_count&gt;</em></li>
	<li><strong><a name="SetConfig"></a>SetConfig</strong>
<em>&lt;string config_var&gt; &lt;string value&gt;</em></li>
	<li><strong><a name="SetDemeResource"></a>SetDemeResource</strong>
<em>&lt;string res_name&gt; &lt;double res_count&gt;</em></li>
	<li><strong><a name="SetDemeResourceInflow"></a>SetDemeResourceInflow</strong>
<em>&lt;int deme id&gt; &lt;string resource_name&gt; &lt;double inflow&gt;</em></li>
	<li><strong><a name="SetDemeResourceOutflow"></a>SetDemeResourceOutflow</strong>
<em>&lt;int deme id&gt; &lt;string resource_name&gt; &lt;double outflow&gt;</em></li>
	<li><strong><a name="SetEnvironmentInputs"></a>SetEnvironmentInputs</strong>
<em>&lt;int input_1&gt; &lt;int input_2&gt; &lt;int input_3&gt; </em>Set the inputs that all organisms get from the environment when doing IO to these specific values. There must
be exactly three inputs, and they must have the usual values for the top 8 "key" bits, i.e. they must be of the form
0x0F?????? 0x33?????? 0x55?????? where ? can be replaced with any hexadecimal digit.</li>
	<li><strong><a name="SetEnvironmentRandomMask"></a>SetEnvironmentRandomMask</strong>
<em>&lt;int mask&gt;</em></li>
	<li><strong><a name="SetFracDemeTreatable"></a>SetFracDemeTreatable</strong></li>
  <li><p>
    <strong><a name="SetGradientResource">SetGradientResource</a></strong>
    <i>&lt;string env_string&gt;</i>
    </p>
    <p>
    Action designed to read in and process a line for ONE gradient resource,
    formatted as if it were in the <a href="gradient.html">environment</a> file.  
    This will change environmental settings for this one gradient resource on the fly.  
    You should create the resource in the environment file and only use this file to 
    change this resource. <br>
    Unlike with ChangeEnvironment, no resources other than the one specified in the event
    will be affected.
    </p>
  </li>  
  <li><p>
    <strong><a name="SetGradientInflow">SetGradientInflow</a></strong>
    <i>&lt;string res_name&gt; &lt;double res_inflow&gt;</i>
    </p>
    <p>
    Set existing gradient resource plateau inflow rate to a new value, without redrawing
    the entire resource.
    </p>
  </li>  
  <li><p>
    <strong><a name="SetGradientOutflow">SetGradientOutflow</a></strong>
    <i>&lt;string res_name&gt; &lt;double res_outflow&gt;</i>
    </p>
    <p>
    Set existing gradient resource plateau outflow rate to a new value, without redrawing
    the entire resource.
    </p>
  </li>  
    <li><p>
    <strong><a name="SetGradientConeInflow">SetGradientConeInflow</a></strong>
    <i>&lt;string res_name&gt; &lt;double res_inflow&gt;</i>
  </p>
</li>
    <li><p>
    <strong><a name="SetGradientConeOutflow">SetGradientConeOutflow</a></strong>
    <i>&lt;string res_name&gt; &lt;double res_outflow&gt;</i>
  </p>
</li>
    <li><p>
    <strong><a name="SetGradientPlatInflow">SetGradientPlatInflow</a></strong>
    <i>&lt;string res_name&gt; &lt;double res_inflow&gt;</i>
  </p>
</li>
    <li><p>
    <strong><a name="SetGradientPlatOutflow">SetGradientPlatOutflow</a></strong>
    <i>&lt;string res_name&gt; &lt;double res_outflow&gt;</i>
  </p>
</li>
    <li><p>
    <strong><a name="SetGradPlatVarInflow">SetGradPlatVarInflow</a></strong>
    <i>&lt;string res_name&gt; &lt;double mean&gt; &lt;double variance&gt; &lt;int type&gt;</i>
  </p>
    <p>
    Set existing gradient resource plateau inflow rate to a new value, without redrawing
    the entire resource, based on a random number pull from normal distribution of this
    mean and variance. As such, this uses a half normal or folded normal approach with 
    expected value = sigma * sqrt(2 /pi).
    If type == 0, new inflow will be the random number pulled.
    If type &gt; 0, new inflow will be mean + abs(the random number pulled).
    If type == 1, new inflow will be max (0, mean - abs(the random number pulled)).
    If type == 2, new inflow will be max (0, mean + the random number pulled).
    </p>
</li>

	<li><strong><a name="SetNumInstBefore0Energy"></a>SetNumInstBefore0Energy</strong>
<em>&lt;int new_value&gt;</em></li>
	<li><strong><a name="SetOptimizeMinMax"></a>SetOptimizeMinMax</strong>
<em>No Arguments</em></li>
	<li><strong><a name="SetPeriodicResource"></a>SetPeriodicResource</strong>
<em>&lt;string reaction_name&gt; &lt;string amplitude&gt; &lt;string pi/frequence&gt; &lt;phaseShift*pi&gt; &lt;string initial_Y&gt;</em></li>
	<li><strong><a name="SetReactionInst"></a>SetReactionInst</strong>
<em>&lt;string reaction_name&gt; &lt;string inst&gt;</em>Set the instruction triggered by this reaction.
<span class="cmdarg">reaction_name</span> must already
exist in the environment file.
<span class="cmdarg">inst</span> must be in the instruction set.</li>
<li><p>
  <strong><a name="SetPopCapEnforcement">SetPopCapEnforcement</a></strong>
  <i>[int cap=0] [int rate=1]</i>
  </p>
  <p>
  Will set POPULATION_CAP to cap and begin killing orgs off at rate rate by killing rate # orgs + 1 every time a new org is born.
  Accepts string args (e.g. SetPopCapEnforcement cap=0:rate=1).
  </p>
</li>
    <li><p>
    <strong><a name="SetPredatoryResource">SetPredatoryResource</a></strong>
    <i>&lt;string res_name&gt; &lt;double kill_odds&gt; &lt;double guarded_juvs_per_adult&gt;double detection_prob&gt;</i>
  </p>
    <p>
    A gradient resource with teeth. If set in motion, will kill with prob kill_odds 1 random org 
    in each cell of plateau. If it passes over a den resource, will kill unguarded offspring with
    probability kill_odds. If an org steps on the resource, the org is killed with probability
    kill_odds. detection_prob sets the probability of orgs detecting the predator via look sensors.
    </p>
</li>

	<li><strong><a name="SetReactionMaxTaskCount"></a>SetReactionMaxTaskCount</strong>
<em>&lt;string reaction_name&gt; &lt;int max_count&gt;</em>Set the max task count required to trigger a reaction to <span class="cmdarg">task_count</span>.
<span class="cmdarg">reaction_name</span> must already
exist in the environment file.</li>
	<li><strong><a name="SetReactionMinTaskCount"></a>SetReactionMinTaskCount</strong>
<em>&lt;string reaction_name&gt; &lt;int min_count&gt;</em>Set the min task count required to trigger a reaction to <span class="cmdarg">task_count</span>.
<span class="cmdarg">reaction_name</span> must already
exist in the environment file.</li>
	<li><strong><a name="SetReactionTask"></a>SetReactionTask</strong>
<em>&lt;string reaction_name&gt; &lt;string task_name&gt;</em>Set the task required to trigger a reaction to <span class="cmdarg">task_name</span>.
<span class="cmdarg">reaction_name</span> and <span class="cmdarg">task_name</span> must already
exist in the environment file.</li>
	<li><strong><a name="SetReactionValue"></a>SetReactionValue</strong>
<em>&lt;string reaction_name&gt; &lt;double value&gt;</em>Set the reaction value to a specific level.
<span class="cmdarg">reaction_name</span> must already
exist in the environment file.
<span class="cmdarg">value</span> can be negative.</li>
	<li><strong><a name="SetReactionValueMult"></a>SetReactionValueMult</strong>
<em>&lt;string reaction_name&gt; &lt;double value&gt;</em>Multiply the reaction value by the <span class="cmdarg">value</span>.
<span class="cmdarg">reaction_name</span> must already
exist in the environment file.
<span class="cmdarg">value</span> can be negative.</li>
	<li><strong><a name="SetResource"></a>SetResource</strong>
<em>&lt;string res_name&gt; &lt;double res_count&gt;</em>Set the resource amount to a specific level.
<span class="cmdarg">res_name</span> must already exist as
a resource in environment file.</li>
	<li><strong><a name="SetResourceInflow"></a>SetResourceInflow</strong>
<em>&lt;string resource_name&gt; &lt;double inflow&gt;</em>Set the resource inflow to a specific level.
<span class="cmdarg">res_name</span> must already exist as
a resource in environment file.</li>
	<li><strong><a name="SetResourceOutflow"></a>SetResourceOutflow</strong>
<em>&lt;string resource_name&gt; &lt;double outflow&gt;</em>Set the resource outflow to a specific level.
<span class="cmdarg">res_name</span> must already exist as
a resource in environment file.</li>
	<li><strong><a name="SetSeasonalResource"></a>SetSeasonalResource</strong>Sets resource availiblity to seasonal</li>
	<li><strong><a name="SetSeasonalResource10Kyears_1To_1"></a>SetSeasonalResource10Kyears_1To_1</strong>Sets resource availiblity to seasonal 1 to -1 for 10K years of 365 updates</li>
	<li><strong><a name="SetSeasonalResource1Kyears_1To_1"></a>SetSeasonalResource1Kyears_1To_1</strong>Sets resource availiblity to seasonal 1 to -1 for 1K years of 365 updates</li>
	<li><strong><a name="SetTaskArgDouble"></a>SetTaskArgDouble</strong>
<em>&lt;int task&gt; &lt;int arg&gt; &lt;double value&gt;</em></li>
	<li><strong><a name="SetTaskArgInt"></a>SetTaskArgInt</strong>
<em>&lt;int task&gt; &lt;int arg&gt; &lt;int value&gt;</em></li>
	<li><strong><a name="SetTaskArgString"></a>SetTaskArgString</strong>
<em>&lt;int task&gt; &lt;int arg&gt; &lt;string value&gt;</em></li>
	<li><strong><a name="ZeroResources"></a>ZeroResources</strong>
<em>none</em>Set all resurce levels to zero.</li>
</ul>
&nbsp;
<h2><a name="LandscapeActions"></a>Landscape Analysis Actions</h2>
Landscape analysis actions perform various types mutation studies to
calculate properties of the fitness landscape for a particular genome.
When scheduled as an event during a run, these actions will typically
perform analysis on the dominant genotype. In analyze mode, analysis
is performed on the entire currently selected batch.

These actions are often very computationally intensive, thus will
take a long time to compute. In order to take advantage of increasingly
available multi-processor/multi-core systems, a number of these actions
have been enhanced to make use of multiple threads to parallize work.
Set the configuration setting <code>MT_CONCURRENCY</code> to the number
of logical processors available to make use of all processor resources
for these compuations.
<ul>
	<li><strong><a name="AnalyzeLandscape"></a>AnalyzeLandscape</strong>
<em>[filename="land-analyze.dat"] [int trials=1000] [int min_found=0] [int max_trials=0] [int max_dist=10]</em></li>
	<li><strong><a name="AnalyzePopulation"></a>AnalyzePopulation</strong>
<em>[double sample_prob=1] [int landscape=0] [int save_genotype=0] [string filename=""]</em></li>
	<li><strong><a name="DeletionLandscape"></a>DeletionLandscape</strong>
<em>[string filename="land-del.dat"] [int distance=1] [string sitecount_file=""]</em></li>
	<li><strong><a name="DumpLandscape"></a>DumpLandscape</strong>
<em>[string filename="land-dump.dat"]</em></li>
	<li><strong><a name="FullLandscape"></a>FullLandscape</strong>
<em>[string filename="land-full.dat"] [int distance=1] [string entropy_file=""] [string sitecount_file=""]</em>Do a landscape analysis of the dominant genotype or current batch of genotypes,
depending on the current mode. The resulting output is a collection of
statistics obtained from examining all possible mutations at the distance
specified. The default distance is one.</li>
	<li><strong><a name="HillClimb"></a>HillClimb</strong>
<em>[string filename="hillclimb.dat"]</em>Does a hill climb with the dominant genotype.</li>
	<li><strong><a name="InsertionLandscape"></a>InsertionLandscape</strong>
<em>[string filename="land-ins.dat"] [int distance=1] [string sitecount_file=""]</em></li>
	<li><strong><a name="MutationalNeighborhood"></a>MutationalNeighborhood</strong>
<em>[string fname="mut-neighborhood.dat"] [int target=-1]</em></li>
	<li><strong><a name="PairTestLandscape"></a>PairTestLandscape</strong>
<em>[string filename=""] [int sample_size=0]</em>If sample_size = 0, pairtest the full landscape.</li>
	<li><strong><a name="PrecalcLandscape"></a>PrecalcLandscape</strong>
<em>No Arguments</em>Precalculate the distance 1 full landscape for the current batch in parallel
using multiple threads. The resulting data is stored into the current batch
and can be used by many subsequent output commands within Analyze mode.</li>
	<li><strong><a name="PredictNuLandscape"></a>PredictNuLandscape</strong>
<em>[string filename="land-predict.dat"]</em></li>
	<li><strong><a name="PredictWLandscape"></a>PredictWLandscape</strong>
<em>[string filename="land-predict.dat"]</em></li>
	<li><strong><a name="RandomLandscape"></a>RandomLandscape</strong>
<em>[string filename="land-random.dat"] [int distance=1] [int trials=0]</em></li>
	<li><strong><a name="SampleLandscape"></a>SampleLandscape</strong>
<em>[string filename="land-sample.dat"] [int trials=0]</em></li>
</ul>
&nbsp;
<h2><a name="PopulationActions"></a>Population Actions</h2>
Population events modify the state of the population, and will actually
change the course of the run. There are a wide variety of these.
<ul>
	<li><strong><a name="AssignRandomCellData"></a>AssignRandomCellData</strong>
<em>[num_cells=deme_size]</em></li>
<li><p>
  <strong><a name="AttackDen">AttackDen</a></strong>
  <i>[double probability=0.0] [int juvs_per_adult=1]</i>
  </p>
  <p>
  Kills each unguarded juv in dens (habitat == 3 or 4) with set probability. juvs_per_adult sets
  the ratio of guarding adults to juvs. E.g. if ratio is set to 5 and there are 2 guards and 12
  juveniles in a den, two random juveniles will be attacked with their probability of death at
  the set probability.
  </p>
</li>
	<li><strong><a name="AvidianConjugation"></a>AvidianConjugation</strong>
<em>(prob. of donation)</em></li>
	<li><strong><a name="CompeteDemes"></a>CompeteDemes</strong>
<em>[int type=1]</em></li>
	<li><strong><a name="CompeteDemes_AttackKillAndEnergyConserve"></a>CompeteDemes_AttackKillAndEnergyConserve</strong>
<em>No Arguments</em></li>
	<li><strong><a name="CompeteDemesByEnergyDistribution"></a>CompeteDemesByEnergyDistribution</strong>
<em>Competes demes according to the distribution of energy among the organisms</em></li>
	<li><strong><a name="CompeteDemesByNetwork"></a>CompeteDemesByNetwork</strong>
<em>No arguments.</em></li>
	<li><strong><a name="CompeteDemesByTaskCount"></a>CompeteDemesByTaskCount</strong>
<em>Competes demes according to the number of times a given task has been completed within that deme</em>Competes demes based on the total number of times that a
task has been completed by an organism in the deme since the
was initialized. This action takes one integer parameter representing
number of the task that is to be used for competition. If no parameter
supplied, the class uses the first task defined in the environment file
compete the demes.</li>
	<li><strong><a name="CompeteDemesByTaskCountAndEfficiency"></a>CompeteDemesByTaskCountAndEfficiency</strong>
<em>Competes demes according to the number of times a given task has been completed within that deme and the efficiency with which it was done</em></li>
	<li><strong><a name="CompeteOrganisms"></a>CompeteOrganisms</strong>
<em>[int type=0] [int parents_survive=0] [double scaled_time=1.0] [int dynamic_scaling=0]</em>Calculates fitness of each organism in the population and creates a new population of descendants
where each organism has a chance of replication proportional to its fitness. Can be used to make Avida
operate without population dynamics and asynchronous replication, i.e. like a genetic algorithm. If NewTrial
events have occurred since the last CompeteOrganisms event, then the average fitness over those trials
will be used.<code>competition_type</code> controls how the fitnesses of multiple trials determine the overall fitness
used for the competition: 0=geometric mean of fitnesses, 1=scaled geometric mean of fitnesses (the greatest fitness
of each trial is scaled to 1.0 before taking the geometric mean), 2=arithmetic mean, 3=geometric mean plus
rescales effective fitness values by the geometric mean of the difference from the top score and the median.Setting <code>parents_survive</code> to 1, causes the first copy of an organism that makes it into the new
population to be the original (unmutated) parent organism.</li>
	<li><strong><a name="ConnectCells"></a>ConnectCells</strong>
<em>&lt;int cellA_x&gt; &lt;int cellA_y&gt; &lt;int cellB_x&gt; &lt;int cellB_y&gt;</em>Connects a pair of specified cells.</li>
	<li><strong><a name="CopyDeme"></a>CopyDeme</strong>
<em>&lt;int src_id&gt; &lt;int dest_id&gt;</em></li>
	<li><strong><a name="CountMultipleOpinions"></a>CountMultipleOpinions</strong>
<em>[int opinion_count=0]</em></li>
	<li><strong><a name="CountOpinions"></a>CountOpinions</strong>
<em>[int desired_opinion=0 [int multiplicity=1 [int side=0]]]</em></li>
	<li><strong><a name="DecayPoints"></a>DecayPoints</strong>
<em>No Arguments</em>Decays the number of points a deme has accumulated by
a percentage that is set in the configuration file.</li>
	<li><strong><a name="DemeBalanceTwoTasks"></a>DemeBalanceTwoTasks</strong>
<em>Two min and max for not</em></li>
	<li><strong><a name="DemeReactionDiversity"></a>DemeReactionDiversity</strong>
<em>No arguments.</em></li>
	<li><strong><a name="DemeResourceThresholdPredicate"></a>DemeResourceThresholdPredicate</strong>
<em>cString resourceName, cString comparisonOperator, double threasholdValue</em></li>
	<li><strong><a name="Desynchronization"></a>Desynchronization</strong>
<em>No Arguments</em></li>
	<li><strong><a name="DiffuseHGTGenomeFragments"></a>DiffuseHGTGenomeFragments</strong>
<em>&lt;none&gt;</em></li>
	<li><strong><a name="DisconnectCells"></a>DisconnectCells</strong>
<em>&lt;int cellA_x&gt; &lt;int cellA_y&gt; &lt;int cellB_x&gt; &lt;int cellB_y&gt;</em>Disconnects a pair of specified cells.</li>
	<li><strong><a name="DistributeData"></a>DistributeData</strong>
<em>No arguments.</em></li>
	<li><strong><a name="DistributeDataCheaply"></a>DistributeDataCheaply</strong>
<em>No arguments.</em></li>
	<li><strong><a name="DistributeDataEfficiently"></a>DistributeDataEfficiently</strong>
<em>No arguments.</em></li>
	<li><strong><a name="DivideDemes"></a>DivideDemes</strong>
<em>No arguments (yet!)</em></li>
	<li><strong><a name="Flash"></a>Flash</strong>
<em>No arguments</em></li>
<li><p>
  <strong><a name="FlushTopNavTrace">FlushTopNavTrace</a></strong><em>No arguments</em></li>
  Force printing of nav trace (as set up by PrintTopNavTrace) even if all candidate orgs have not been
  evaluated / reproduced.
    </p>
</li>
	<li><strong><a name="Inject"></a>Inject</strong>
<em>[string fname="START_ORGANISM"] [int cell_id=0] [double merit=-1] [int lineage_label=0] [double neutral_metric=0]</em>Inject a single organisms into the population. Arguments must be
included from left to right; if all arguments are left out, the default
creature is the ancestral organism, and it will be injected into cell 0,
have an uninitialized merit, and be marked as liniage id 0.</li>
	<li><strong><a name="InjectAll"></a>InjectAll</strong>
<em>[string fname="START_ORGANISM"] [double merit=-1] [int lineage_label=0] [double neutral_metric=0]</em>Same as Inject, but no cell_id is specified and the organism is placed
into <em>all</em> cells in the population.</li>
	<li><strong><a name="InjectAllRandomRepro"></a>InjectAllRandomRepro</strong>
<em>&lt;int length&gt; [double merit=-1] [int lineage_label=0] [double neutral_metric=0]</em></li>
	<li><strong><a name="InjectCanvas"></a>InjectCanvas</strong>
<em>[string fname="START_ORGANISM"] [int canvas_id=0] [int canvas_x=0] [int canvas_y=0] [int group_id=-1] [int forager_type=-1] [double merit=-1] [int lineage_label=0] [double neutral_metric=0]</em></li>
	<li><strong><a name="InjectDemes"></a>InjectDemes</strong>
<em>[string fname="START_ORGANISM"] [double merit=-1] [int lineage_label=0] [double neutral_metric=0]</em></li>
	<li><strong><a name="InjectDemesFromNest"></a>InjectDemesFromNest</strong>
<em>[int num_orgs=1] [int nest_cellid=0] [double merit=-1] [int lineage_label=0] [double neutral_metric=0]</em></li>
	<li><strong><a name="InjectDemesRandom"></a>InjectDemesRandom</strong>
<em>[int num_orgs=1] [double merit=-1] [int lineage_label=0] [double neutral_metric=0]</em></li>
	<li><strong><a name="InjectGroup"></a>InjectGroup</strong>
<em>[string fname="START_ORGANISM"] [int cell_id=0] [int group_id=-1] [int forager_type=-1] [double merit=-1] [int lineage_label=0] [double neutral_metric=0]</em></li>
	<li><strong><a name="InjectModuloDemes"></a>InjectModuloDemes</strong>
<em>[string fname="START_ORGANISM"] [int mod_num = 1] [double merit=-1] [int lineage_label=0] [double neutral_metric=0]</em></li>
	<li><strong><a name="InjectParasite"></a>InjectParasite</strong>
<em>&lt;string filename&gt; &lt;string label&gt; [int cell_start=0] [int cell_end=-1]</em>Attempt to inject a parasite genome into the supplied population cell
range with the specified label.</li>
	<li><strong><a name="InjectParasitePair"></a>InjectParasitePair</strong>
<em>&lt;string filename_genome&gt; &lt;string filename_parasite&gt; &lt;string label&gt; [int cell_start=0] [int cell_end=-1] [double merit=-1] [int lineage_label=0] [double neutral_metric=0]</em>Inject host parasite pairs into the population cell range specified.</li>
	<li><strong><a name="InjectRandom"></a>InjectRandom</strong>
<em>&lt;int length&gt; [int cell_id=0] [double merit=-1] [int lineage_label=0] [double neutral_metric=0]</em>Injects a randomly generated genome of the supplied length into the population.</li>
	<li><strong><a name="InjectRange"></a>InjectRange</strong>
<em>[string fname="START_ORGANISM"] [int cell_start=0] [int cell_end=-1] [double merit=-1] [int lineage_label=0] [double neutral_metric=0]</em>Injects identical organisms into a range of cells of the population.<em>Example</em>:<code>InjectRange 000-aaaaa.org 0 10</code>Will inject 10 organisms into cells 0 through 9.</li>
	<li><strong><a name="InjectSequence"></a>InjectSequence</strong>
<em>&lt;string sequence&gt; [int cell_start=0] [int cell_end=-1] [double merit=-1] [int lineage_label=0] [double neutral_metric=0]</em>Injects identical organisms based on the supplied genome sequence into
a range of cells of the population.<em>Example</em>:<code>InjectSequence ckdfhgklsahnfsaggdsgajfg 0 10 100</code>Will inject 10 organisms into cells 0 through 9 with a merit of 100.</li>
	<li><strong><a name="InjectSequenceWDivMutRate"></a>InjectSequenceWDivMutRate</strong>
<em>&lt;string sequence&gt; [int cell_start=0] [int cell_end=-1] [double div_mut_rate=0] [double merit=-1] [int lineage_label=0] [double neutral_metric=0]</em></li>
	<li><strong><a name="IteratedConsensus"></a>IteratedConsensus</strong>
<em>[int compete_period=100 [int replace_number=1 [int kill=1 [int restrict_range=1]]]]</em></li>
	<li><strong><a name="JoinGridCol"></a>JoinGridCol</strong>
<em>[int col_id=-1] [int min_row=0] [int max_row=-1]</em>Add connections between cells along a column in an Avida grid.</li>
	<li><strong><a name="JoinGridRow"></a>JoinGridRow</strong>
<em>[int row_id=-1] [int min_col=0] [int max_col=-1]</em>Add connections between cells along a row in an Avida grid.</li>
	<li><strong><a name="KillFractionInSequence"></a>KillFractionInSequence</strong>
<em>[double fraction=0.01]</em></li>
	<li><strong><a name="KillFractionInSequence_PopLimit"></a>KillFractionInSequence_PopLimit</strong>
<em>[double fraction=0.01]</em></li>
	<li><strong><a name="KillInstLimit"></a>KillInstLimit</strong>
<em>[double probability=0.9] [cString inst=nand] [int limit=5]</em></li>
	<li><strong><a name="KillInstPair"></a>KillInstPair</strong>
<em>[double probability=0.9] [cString inst1=nand] [cString inst2=nor] [int limit=1]</em></li>
	<li><strong><a name="KillMeanBelowThresholdPaintable"></a>KillMeanBelowThresholdPaintable</strong></li>
	<li><strong><a name="KillNBelowResourceThreshold"></a>KillNBelowResourceThreshold</strong>
<em>[int numkills=0, string resource name, double threshold=0]</em></li>
	<li><strong><a name="KillProb"></a>KillProb</strong>
<em>[double probability=0.9]</em>Using the specified probability, test each organism to see if it is killed off.</li>
	<li><strong><a name="KillRate"></a>KillRate</strong>
<em>[double probability=0.9]</em>Randomly removes a certain proportion of the population.
In principle, this action does the same thing as the KillProb event.
However, instead of a probability, here one has to specify a rate. The
rate has the same unit as fitness. So if the average fitness is 20000,
than you remove 50% of the population on every update with a removal rate
of 10000.</li>
	<li><strong><a name="KillRectangle"></a>KillRectangle</strong>
<em>[int x1=0] [int y1=0] [int x2=0] [int y2=0]</em>Kill off all organisms in a rectangle defined by the points (x1, y1) and (x2, y2).</li>
	<li><strong><a name="KillWithinRadiusBelowResourceThreshold"></a>KillWithinRadiusBelowResourceThreshold</strong>
<em>[int numradii=0, int radius=0, string resource name, double threshold=0, double killdensity=1]</em></li>
	<li><strong><a name="KillWithinRadiusBelowResourceThresholdTestAll"></a>KillWithinRadiusBelowResourceThresholdTestAll</strong>
<em>[int numradii=0, int radius=0, string resource name, double threshold=0, double killdensity=1]</em></li>
	<li><strong><a name="KillWithinRadiusMeanBelowResourceThreshold"></a>KillWithinRadiusMeanBelowResourceThreshold</strong>
<em>[int numradii=0, int radius=0, string resource name, double threshold=0, double killdensity=1]</em></li>
	<li><strong><a name="MeasureDemeNetworks"></a>MeasureDemeNetworks</strong>
<em>No arguments.</em></li>
	<li><strong><a name="MixPopulation"></a>MixPopulation</strong>
<em>No arguments.</em></li>
	<li><strong><a name="ModMutProb"></a>ModMutProb</strong>
<em>[string mut_type="COPY_MUT"] [double prob=0.0] [int start_cell=-1] [int end_cell=-1]</em>Values for mut_type are POINT, COPY_MUT, COPY_INS, COPY_DEL, COPY_UNIFORM, COPY_SLIP, DIV_MUT, DIV_INS, DIV_DEL, DIV_UNIFORM, DIV_SLIP, DIVIDE_MUT, DIVIDE_INS, DIVIDE_DEL, DIVIDE_UNIFORM, DIVIDE_SLIP, PARENT, INJECT_MUT, INJECT_INS, and INJECT_DEL. These correspond to their counterparts in avida.cfg.To turn off all mutations, use <a href="#ZeroMuts">ZeroMuts</a>.</li>
	<li><strong><a name="NewTrial"></a>NewTrial</strong>
<em>No Arguments</em>Immediately calculates the fitness of each organism in the population, saves this value for use with the CompeteOrganisms
event, and resets the state of all organisms.</li>
	<li><strong><a name="PhenotypeMatch"></a>PhenotypeMatch</strong>
<em>string file-name</em></li>
	<li><strong><a name="Pred_DemeEventMoveBetweenTargets"></a>Pred_DemeEventMoveBetweenTargets</strong>
<em>[int times=1]</em></li>
	<li><strong><a name="Pred_DemeEventMoveCenter"></a>Pred_DemeEventMoveCenter</strong>
<em>[int times=1]</em></li>
	<li><strong><a name="Pred_DemeEventNUniqueIndividualsMovedIntoTarget"></a>Pred_DemeEventNUniqueIndividualsMovedIntoTarget</strong>
<em>[int numorgs=1]</em></li>
  <li><p>
    <strong><a name="PrintMiniTraces">PrintMiniTraces</a></strong>
    <i>[boolean random=0] [boolean save_dominants=0] [boolean save_groups=0] [boolean save_foragers=0] [int orgs_per=1] [int max_samples=0] [boolean print_genomes=0] [boolean initial]</i>
    </p>
    <p>Prints a condensed trace of execution during a lifetime. Who is traced is determined by arguements.
    E.g. with the args save_dominants=1:orgs_per=2, at the specified update(s) a list is
    created containing the two most abundant genotypes. The next offspring born <i>to parents</i> with those specified
    genotypes will then be traced for their entire lifetimes. If save_foragers is set to 1, the list 
    would contain the two most abundant genotypes for EACH existing forager type. Multiple types can
    be saved without duplicating traces. E.g. save_dominants=1:save_foragers=1:orgs_per=2 would
    trace one org from each of the two most dominant genotypes and one org from each of the two most 
    common genotypes for each of the existing forager types if those genotypes were not also one of the
    two most abundant overall. If max_samples is &gt; 0, this will cap the total number of orgs traced with
    priorities on fullfilling orgs_per quota for: dominants &gt; forager types &gt; group ids.
    </p>
    <p> Setting random will look at current population, select individuals up to max_samples (without replacement)
    record the sampled genotypes (one per individual, including genotype duplicates) and then trace the next orgs 
    born with those genotypes, removing the genotype instance from the 'to-do' list with each new trace. Random option
    is not currently compatible with (will override) other save_ arguements or orgs_per.
    </p>
    <p> Minitraces are currently only fully implemented for the experimental hardware and partially for 
    the SMT hardware because of differences in the way some minitrace variables are tracked by the 
    different hardware types.
    </p>
    <p> Each call to PrintMiniTraces resets the genotype list, rather than appending to it.
    </p>
    <p>
    
    </p>
  </li>
    <strong><a name="PrintMicroTraces">PrintMicroTraces</a></strong>
    <i>[boolean random=0] [boolean rand_prey=0] [boolean rand_pred=0] [int next_prey=0] [int next_pred=0] [boolean save_dominants=0] [boolean save_groups=0] [boolean save_foragers=0] [int orgs_per=1] [int max_samples=0] [boolean print_genomes=0]</i>
    </p>
    <p>Same general operation behavior as PrintMiniTraces but only saves executed instruction symbols along with 
    org id, genotype id, forager type, and birth and death updates. Microtraces map executions as 'what the org was trying
    to do'. So, failed executions are recorded except when CPU costs are being paid. If CPU costs are being paid, we record
    the execution when the instruction was submitted, not necessarily when it was actually executed. Each microtrace is 
    saved on a single line in microtrace.dat.
    </p>
    <p> rand_pred and rand_prey are compatible with each other, building a single list of genotypes to trace based on
    current genotypes in the population for each of the two general forager types (will generate a list of 2 X max_samples
    if both arguements are used).
    </p>
    <p> Each call to PrintMicroTraces appends to the genotype list, rather than replacing it (opposite of mini traces).
    </p>
    <p> If next_prey or next_pred are used, the organisms born to parents with prey or predator 
    foraging targets will be traced, regardless of genotype, until the set arg number have been traced (requested number will
    be replaced, not appended to, by subsequent event calls). </p>
    <p>
    </p>
  </li>
	<li><strong><a name="RemovePredators"></a>RemovePredators</strong><em></em></li>
	<li><strong><a name="ReplaceFromGermline"></a>ReplaceFromGermline</strong>
<em>[double p(kill)=0.0 [int update_cell_data=0]]</em></li>
	<li><strong><a name="ReplicateDemes"></a>ReplicateDemes</strong>
<em>[string trigger=full_deme]</em>
        <p>Tests all demes in a population and replicates those wherein a specific trigger condition has been met.  The available triggers are:
           <ul>
             <li><i>full_deme</i>: All deme cells are occupied by organisms.</li>
             <li><i>corners</i>: The upper-left and lower-right cells in a deme are occupied</li>
             <li><i>deme-age</i>: The deme has reached the age specified as DEMES_MAX_AGE in avida.cfg</li>
             <li><i>birth-count</i>: The deme has reached the number of births specified as DEMES_MAX_BIRTHS in avida.cfg</li>
             <li><i>sat-mov-pred</i>: ???</li>
             <li><i>events-killed</i>: ???</li>
             <li><i>sat-msg-pred</i>: ???</li>
             <li><i>sat-deme-predicate</i>: ???</li>
             <li><i>perf-reactions</i>: ???</li>
             <li><i>consume-res</i>: The deme has consumed a total number of resources specified as RES_FOR_DEME_REP in avida.cfg</li>
           </ul>
        </p>
        </li>
	<li><strong><a name="ResetDemes"></a>ResetDemes</strong>
<em>No Arguments</em></li>
	<li><strong><a name="SerialTransfer"></a>SerialTransfer</strong>
<em>[int transfer_size=1] [int ignore_deads=1]</em>Similar to KillProb, but we specify the exact number of organisms to
keep alive after the event. The <span class="cmdarg">ignore_deads</span>
argument determines whether only living organisms are retainted.</li>
	<li><strong><a name="SetMigrationRate"></a>SetMigrationRate</strong>
<em>[double rate=0.0]</em></li>
	<li><strong><a name="SetMutProb"></a>SetMutProb</strong>
<em>[string mut_type="COPY_MUT"] [double prob=0.0] [int start_cell=-1] [int end_cell=-1]</em>For a list of values for mut_type, see <a href="#SetMutProb">SetMutProb</a>.</li>
	<li><strong><a name="SeverGridCol"></a>SeverGridCol</strong>
<em>[int col_id=-1] [int min_row=0] [int max_row=-1]</em>Remove the connections between cells along a column in an Avida grid.</li>
	<li><strong><a name="SeverGridRow"></a>SeverGridRow</strong>
<em>[int row_id=-1] [int min_col=0] [int max_col=-1]</em>Remove the connections between cells along a row in an Avida grid.</li>
	<li><strong><a name="SwapCells"></a>SwapCells</strong>
<em>&lt;int cell_id1&gt; &lt;int cell_id2&gt;</em> Swaps the two organisms and all associated information (such as previous inputs). Doesn't work with identical cell ids.</li>
	<li><strong><a name="SwapRandomCells"></a>SwapRandomCells</strong>
<em>&lt;int number swaps&gt;</em> Swaps the specified number of pairs of randomly selected organisms. If randomly selected ids happen to be the same, nothing happens that iteration. </li>
	<li><strong><a name="Synchronization"></a>Synchronization</strong>
<em>No Arguments</em></li>
	<li><strong><a name="TherapyDecayDemeResource"></a>TherapyDecayDemeResource</strong>
<em>[string resource_name=resname, string decrease_type=(none|lin|exp), double amount=0.2]</em></li>
	<li><strong><a name="TherapyStructuralNumInst"></a>TherapyStructuralNumInst</strong>
<em>[cString inst=nand] [double exprWeight=1.0] [double exponent=1.0(linear)]</em></li>
	<li><strong><a name="TherapyStructuralRatioDistBetweenNearest"></a>TherapyStructuralRatioDistBetweenNearest</strong>
<em>[cString inst=nand] [double exprWeight=1.0] [double exponent=1.0(linear)] [int print=100]</em></li>
	<li><strong><a name="ToggleFitnessValley"></a>ToggleFitnessValley</strong>
<em>No Arguments</em></li>
	<li><strong><a name="ToggleRewardInstruction"></a>ToggleRewardInstruction</strong>
<em>No Arguments</em></li>
	<li><strong><a name="TrackAllMessages"></a>TrackAllMessages</strong>
<em>No Arguments</em></li>
	<li><strong><a name="UnitFitness"></a>UnitFitness</strong>
<em>No arguments.</em></li>
	<li><strong><a name="ZeroMuts"></a>ZeroMuts</strong>
<em>No Arguments</em>This event will set all mutation rates to zero. That is, it will set all cell mutation rates to zero, so that new organisms born will have zero mutation rates. Current organisms will not be affected, and may still mutate.</li>
</ul>
&nbsp;
<h2><a name="PrintActions"></a>Print Actions</h2>
Output events are the primary way of saving data from an Avida experiments.
The main two types are <em>continuous output</em>, which append to a single file
every time the event is trigged, and <em>singular output</em>, which produce
a single, complete file for each trigger.
<ul>
<ul>
	<li><strong><a name="CalcConsensus"></a>CalcConsensus</strong>
<em>[int lines_saved=0]</em></li>
	<li><strong><a name="DumpCellDataGrid"></a>DumpCellDataGrid</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="DumpClassificationIDGrid"></a>DumpClassificationIDGrid</strong>
<em>[string fname_prefix=""]</em></li>
	<li><strong><a name="DumpDonorGrid"></a>DumpDonorGrid</strong>
<em>[string fname=""]</em>Print out the grid of organisms who donated their merit.</li>
	<li><strong><a name="DumpEnergyGrid"></a>DumpEnergyGrid</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="DumpExecutionRatioGrid"></a>DumpExecutionRatioGrid</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="DumpFitnessGrid"></a>DumpFitnessGrid</strong>
<em>[string fname=""]</em>Print out the grid of organism fitness values.</li>
	<li><strong><a name="DumpGenomeLengthGrid"></a>DumpGenomeLengthGrid</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="DumpGenotypeColorGrid"></a>DumpGenotypeColorGrid</strong>
<em>[int num_colors=12] [string fname=""]</em></li>
	<li><strong><a name="DumpGenotypeGrid"></a>DumpGenotypeGrid</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="DumpHostTaskGrid"></a>DumpHostTaskGrid</strong>
<em>[string fname=""]</em>Print out the grid of takss that host organisms did in the last gestation cycle. For
each host, tasks are first encoded as a binary string (e.g. 100000001 means that
organism is doing NOT and EQU and then reported as a base-10 number (257 in the example above).</li>
	<li><strong><a name="DumpIDGrid"></a>DumpIDGrid</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="DumpLastTaskGrid"></a>DumpLastTaskGrid</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="DumpMaxResGrid"></a>DumpMaxResGrid</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="DumpMemory"></a>DumpMemory</strong>
<em>[string fname=""]</em>Dump memory summary information.</li>
	<li><strong><a name="DumpParasiteGenotypeGrid"></a>DumpParasiteGenotypeGrid</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="DumpParasiteTaskGrid"></a>DumpParasiteTaskGrid</strong>
<em>[string fname=""]</em>Print out the grid of tasks that parasites did last gestation. For each parasite, tasks are first
encoded as a binary string (e.g. 100000001 means that organism is doing NOT and EQU
and then reported as a base-10 number (257 in the example above).</li>
	<li><strong><a name="DumpParasiteVirulenceGrid"></a>DumpParasiteVirulenceGrid</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="DumpPhenotypeIDGrid"></a>DumpPhenotypeIDGrid</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="DumpReactionGrid"></a>DumpReactionGrid</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="DumpReceiverGrid"></a>DumpReceiverGrid</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="DumpSleepGrid"></a>DumpSleepGrid</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="DumpTargetGrid"></a>DumpTargetGrid</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="DumpTaskGrid"></a>DumpTaskGrid</strong>
<em>[string fname=""]</em>Print out the grid of tasks that organisms do. For each organism, tasks are first
encoded as a binary string (e.g. 100000001 means that organism is doing NOT and EQU
and then reported as a base-10 number (257 in the example above).</li>
	<li><strong><a name="DumpVitalityGrid"></a>DumpVitalityGrid</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="Echo"></a>Echo</strong>
<em>&lt;cString message&gt;</em>Print the supplied message to standard output.</li>
	<li><strong><a name="PrintAgePolyethismData"></a>PrintAgePolyethismData</strong>
<em>[string fname="age_polyethism.dat"]</em></li>
	<li><strong><a name="PrintAveNumTasks"></a>PrintAveNumTasks</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="PrintAverageData"></a>PrintAverageData</strong>
<em>[string fname="average.dat"]</em>[<span class="cmdarg">string filename='average.dat'</span>]
Print all of the population averages the specified file.</li>
	<li><strong><a name="PrintAvgDemeTasksExeData"></a>PrintAvgDemeTasksExeData</strong>
<em>[string fname="avg_deme_tasks_exe.dat"]</em></li>
	<li><strong><a name="PrintAvgTreatableDemeTasksExeData"></a>PrintAvgTreatableDemeTasksExeData</strong>
<em>[string fname="avg_treatable_deme_tasks_exe.dat"]</em></li>
	<li><strong><a name="PrintAvgUntreatableDemeTasksExeData"></a>PrintAvgUntreatableDemeTasksExeData</strong>
<em>[string fname="avg_untreatable_deme_tasks_exe.dat"]</em></li>
	<li><strong><a name="PrintBirthChamber"></a>PrintBirthChamber</strong>
<em>[string fname="birth_chamber/bc-XXXX.dat"] [int hwtype=0]</em></li>
	<li><strong><a name="PrintBirthChamberMatingTypeHistogram"></a>PrintBirthChamberMatingTypeHistogram</strong>
<em>[string fname="birth_chamber_mating_type_histogram.dat"] [int hwtype=0]</em></li>
	<li><strong><a name="PrintCCladeCounts"></a>PrintCCladeCounts</strong>
<em>[filename = "cclade_count.dat"]</em>Print a count of the number of oraganisms belonging to a each coalescence clade currently in the population.This action will only work in run mode.This action will require TRACK_CCLADE to be enabled.</li>
	<li><strong><a name="PrintCCladeFitnessHistogram"></a>PrintCCladeFitnessHistogram</strong>
<em>[filename] [fit_mode] [hist_min] [hist_step] [hist_max]</em>Print a histogram of fitnesses for each coalescence clade in the population.This action will only work in run mode.This action will rerequire TRACK_CCLADE to be enabled.<kbd>mode</kbd> may be {<kbd>CURRENT, ACTUAL, TESTCPU</kbd>}, where<kbd>CURRENT</kbd> uses the current phenotype value of fitness</li>
</ul>
</ul>
<kbd>ACTUAL</kbd>uses the current merit and the true gestation time (via test cpu calculation)
<kbd>TESTCPU</kbd>uses the test cpu measurement.
<kbd>lower_bound, step, upper_bound</kbd> are log10 values for the individual histogram bins.

&nbsp;
<ul>
	<li><strong><a name="PrintCCladeRelativeFitnessHistogram"></a>PrintCCladeRelativeFitnessHistogram</strong>
<em>[filename] [fit_mode] [hist_min] [hist_step] [hist_max]</em>Print a histogram of parent-relative fitness ratios for each coalescence clade in the population.This action will only work in run mode.This action will rerequire TRACK_CCLADE to be enabled.<kbd>mode</kbd> may be {<kbd>CURRENT, ACTUAL, TESTCPU</kbd>}, where<kbd>CURRENT</kbd> uses the current phenotype value of fitness</li>
</ul>
<kbd>ACTUAL</kbd>uses the current merit and the true gestation time (via test cpu calculation)
<kbd>TESTCPU</kbd>uses the test cpu measurement.
<kbd>lower_bound, step, upper_bound</kbd> are values for the individual histogram bins.

&nbsp;
<ul>
	<li><strong><a name="PrintCellData"></a>PrintCellData</strong>
<em>[string fname="cell_data.dat"]</em></li>
	<li><strong><a name="PrintCellVisitsData"></a>PrintCellVisitsData</strong>
<em>[string fname="visits.dat "]</em></li>
	<li><strong><a name="PrintCompetitionData"></a>PrintCompetitionData</strong>
<em>[string fname="competition.dat"]</em>Print out CompeteOrganism statistics. Make the first call after the first set of trials has been completed to get a complete header.</li>
	<li><strong><a name="PrintConsensusData"></a>PrintConsensusData</strong>
<em>[string fname="consensus.dat"]</em></li>
	<li><strong><a name="PrintCountData"></a>PrintCountData</strong>
<em>[string fname="count.dat"]</em>Print all of the statistics the keep track of counts (such as the number of organisms
in the population or the number of instructions executed).</li>
	<li><strong><a name="PrintCurrentMeanDemeDensity"></a>PrintCurrentMeanDemeDensity</strong>
<em>[string fname="deme_currentMeanDensity.dat"]</em></li>
	<li><strong><a name="PrintCurrentOpinions"></a>PrintCurrentOpinions</strong>
<em>[string fname="opinions.dat"]</em></li>
	<li><strong><a name="PrintCurrentReactionData"></a>PrintCurrentReactionData</strong>
<em>[string fname="cur_reactions.dat"]</em></li>
	<li><strong><a name="PrintCurrentReactionRewardData"></a>PrintCurrentReactionRewardData</strong>
<em>[string fname="cur_reaction_reward.dat"]</em></li>
	<li><strong><a name="PrintCurrentTaskCounts"></a>PrintCurrentTaskCounts</strong>
<em>[string fname="curr_task_counts.dat"]</em></li>
	<li><strong><a name="PrintData"></a>PrintData</strong>
<em>&lt;cString fname&gt; &lt;cString format&gt;</em>Append to the file specified (continuous output), the data given in the
column list. The column list needs to be a comma-seperated list of
keywords representing the data types. Many possible data types can be
output; see the <a href="PrintData-Options">complete listing</a> for details.
Note that this event will even create a detailed column legend at the top
of your file so you don't need to seperately keep track of what the
columns mean.</li>
	<li><strong><a name="PrintDebug"></a>PrintDebug</strong>
<em>No Arguments</em></li>
	<li><strong><a name="PrintDemeAllStats"></a>PrintDemeAllStats</strong>
<em>No Arguments</em></li>
	<li><strong><a name="PrintDemeAverageData"></a>PrintDemeAverageData</strong>
<em>[string fname="deme_average.dat"]</em></li>
	<li><strong><a name="PrintDemeCompetitionData"></a>PrintDemeCompetitionData</strong>
<em>[string fname="deme_compete.dat"]</em></li>
	<li><strong><a name="PrintDemeCurrentTaskExeData"></a>PrintDemeCurrentTaskExeData</strong>
<em>[string fname=" deme_cur_task_exe.dat "]</em></li>
	<li><strong><a name="PrintDemeDonorStats"></a>PrintDemeDonorStats</strong>
<em>No Arguments</em></li>
	<li><strong><a name="PrintDemeEnergyDistributionStats"></a>PrintDemeEnergyDistributionStats</strong>
<em>No Arguments</em></li>
	<li><strong><a name="PrintDemeEnergySharingStats"></a>PrintDemeEnergySharingStats</strong>
<em>No Arguments</em></li>
	<li><strong><a name="PrintDemeFoundersData"></a>PrintDemeFoundersData</strong>
<em>[string fname="deme_founders.dat"]</em></li>
	<li><strong><a name="PrintDemeGermlineSequestration"></a>PrintDemeGermlineSequestration</strong>
<em>[string fname="deme_germ.dat"]</em></li>
	<li><strong><a name="PrintDemeGlobalResources"></a>PrintDemeGlobalResources</strong>
<em>No Arguments</em>Prints each resource in each deme. The format is different than normal Avida output and no information besides the date and time is given in the comments.
Format at each update:
deme_global_resouces_&lt;update in 6 digits, padded with left 0s&gt; = [ ...
&lt;deme_number&gt; &lt;resource0&gt; etc.
&lt;deme_number&gt; &lt;resource0&gt; etc.
];</li>
	<li><strong><a name="PrintDemeMigrationSuicidePoints"></a>PrintDemeMigrationSuicidePoints</strong>
<em>[string fname=" deme_mig_suicide_points.dat "]</em></li>
	<li><strong><a name="PrintDemeNetworkData"></a>PrintDemeNetworkData</strong>
<em>[string fname="deme_network.dat"]</em></li>
	<li><strong><a name="PrintDemeNetworkTopology"></a>PrintDemeNetworkTopology</strong>
<em>[string fname="deme_network_topology.dat"]</em></li>
	<li><strong><a name="PrintDemeOrgReactionData"></a>PrintDemeOrgReactionData</strong>
<em>[string fname="deme_org_reactions.dat"]</em></li>
	<li><strong><a name="PrintDemeOrgTasksData"></a>PrintDemeOrgTasksData</strong>
<em>[string fname="deme_org_tasks.dat"]</em></li>
	<li><strong><a name="PrintDemeOrgTasksExeData"></a>PrintDemeOrgTasksExeData</strong>
<em>[string fname="deme_org_tasks_exe.dat"]</em></li>
	<li><strong><a name="PrintDemeReactionData"></a>PrintDemeReactionData</strong>
<em>[string fname="deme_reactions.dat"]</em></li>
	<li><strong><a name="PrintDemeReactionDiversityReplicationData"></a>PrintDemeReactionDiversityReplicationData</strong>
<em>[string fname="deme_rx_repl.dat"]</em></li>
	<li><strong><a name="PrintDemeReplicationData"></a>PrintDemeReplicationData</strong>
<em>[string fname="deme_repl.dat"]</em></li>
	<li><strong><a name="PrintDemeResourceStats"></a>PrintDemeResourceStats</strong>
<em>No Arguments</em>Prints each resource in each deme, with the format noted in the initial comments as normal.</li>
	<li><strong><a name="PrintDemeResourceThresholdPredicate"></a>PrintDemeResourceThresholdPredicate</strong>
<em>[string fname="deme_resourceThresholdPredicate.dat"]</em></li>
	<li><strong><a name="PrintDemeSpacialEnergyStats"></a>PrintDemeSpacialEnergyStats</strong>
<em>No Arguments</em></li>
	<li><strong><a name="PrintDemeSpacialSleepStats"></a>PrintDemeSpacialSleepStats</strong>
<em>No Arguments</em></li>
	<li><strong><a name="PrintDemeStats"></a>PrintDemeStats</strong>
<em>No Arguments</em></li>
	<li><strong><a name="PrintDemesTotalAvgEnergy"></a>PrintDemesTotalAvgEnergy</strong>
<em>No Arguments</em></li>
	<li><strong><a name="PrintDemeTasksData"></a>PrintDemeTasksData</strong>
<em>[string fname="deme_tasks.dat"]</em></li>
	<li><strong><a name="PrintDemeTasksExeData"></a>PrintDemeTasksExeData</strong>
<em>[string fname="deme_tasks_exe.dat"]</em></li>
	<li><strong><a name="PrintDemeTestamentStats"></a>PrintDemeTestamentStats</strong>
<em>[string fname="deme_testament.dat"]</em></li>
	<li><strong><a name="PrintDemeTreatableCount"></a>PrintDemeTreatableCount</strong>
<em>[string fname="deme_treatable.dat"]</em></li>
	<li><strong><a name="PrintDemeTreatableReplicationData"></a>PrintDemeTreatableReplicationData</strong>
<em>[string fname="deme_repl_treatable.dat"]</em></li>
	<li><strong><a name="PrintDemeUntreatableReplicationData"></a>PrintDemeUntreatableReplicationData</strong>
<em>[string fname="deme_repl_untreatable.dat"]</em></li>
	<li><strong><a name="PrintDepthHistogram"></a>PrintDepthHistogram</strong>
<em>[string fname="depth_histogram.dat"]</em></li>
	<li><strong><a name="PrintDetailedFitnessData"></a>PrintDetailedFitnessData</strong>
<em>[int save_max_f_genotype=0] [int print_fitness_histo=0] [double hist_fmax=1] [double hist_fstep=0.1] [string datafn="fitness.dat"] [string histofn="fitness_histos.dat"] [string histotestfn="fitness_histos_testCPU.dat"]</em></li>
	<li><strong><a name="PrintDetailedSynchronizationData"></a>PrintDetailedSynchronizationData</strong>
<em>[string fname="sync-detail.dat"]</em></li>
	<li><strong><a name="PrintDirectReciprocityData"></a>PrintDirectReciprocityData</strong>
<em>[string fname="reciprocity.dat"]</em></li>
	<li><strong><a name="PrintDivideMutData"></a>PrintDivideMutData</strong>
<em>[string fname="divide_mut.dat"]</em>Output (regular and log) statistics about individual, per site, rates divide mutation
rates (aver, stdev, skew, cur) to divide_mut.dat. Use with multiple divide instuction set.</li>
	<li><strong><a name="PrintDominantData"></a>PrintDominantData</strong>
<em>[string fname="dominant.dat"]</em>Print all of the statistics relating to the dominant genotype.</li>
	<li><strong><a name="PrintDominantForagerGenotypes"></a>PrintDominantForagerGenotypes</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="PrintDominantGenotype"></a>PrintDominantGenotype</strong>
<em>[string fname=""]</em>Print the dominant organism's genome (and lots of information about it)
into the file specified. If no filename is given, the genotype's assigned name
is used and the file is placed into the archive subdirectory.</li>
	<li><strong><a name="PrintDominantGroupGenotypes"></a>PrintDominantGroupGenotypes</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="PrintDonationStats"></a>PrintDonationStats</strong>
<em>No Arguments</em></li>
	<li><strong><a name="PrintDynamicMaxMinData"></a>PrintDynamicMaxMinData</strong>
<em>[string fname=" maxmin.dat "]</em></li>
	<li><strong><a name="PrintEditDistance"></a>PrintEditDistance</strong>
<em>[sample size [filename]]</em></li>
	<li><strong><a name="PrintErrorData"></a>PrintErrorData</strong>
<em>[string fname="error.dat"]</em>Print all of the standard errors of the average population statistics.</li>
	<li><strong><a name="PrintExtendedTimeData"></a>PrintExtendedTimeData</strong>
<em>[string fname="xtime.dat"]</em></li>
	<li><strong><a name="PrintFemaleMatePreferenceData"></a>PrintFemaleMatePreferenceData</strong>
<em>[string fname="female_mate_preference_data.dat"]</em></li>
	<li><strong><a name="PrintFlowRateTuples"></a>PrintFlowRateTuples</strong>
<em>[string fname="flow_rate_tuples.dat"]</em></li>
	<li><strong><a name="PrintGeneticDistanceData"></a>PrintGeneticDistanceData</strong>
<em>[string ref_creature_file="START_ORGANISM"] [string fname="genetic_distance.dat"]</em></li>
	<li><strong><a name="PrintGenomicSiteEntropy"></a>PrintGenomicSiteEntropy</strong>
<em>[filename = "GenomicSiteEntropyData.dat"]</em>This function will take the initial genotype for each organism in the
population/batch, align them, and calculate the per-site entropy of the
aligned sequences. Please note that there may be a variable number
of columns in each line if the runs are not fixed length. The site
entropy will be measured in mers, normalized by the instruction set size.
This is a population/batch measure of entropy, not a mutation-selection balance
measure.</li>
	<li><strong><a name="PrintGenotypeAbundanceHistogram"></a>PrintGenotypeAbundanceHistogram</strong>
<em>[string fname="genotype_abundance_histogram.dat"]Arguments: [string fname="species_abundance_histogram.dat"]Arguments: [string fname="lineage_totals.dat"] [int verbose=1]Arguments: [string fname="lineage_counts.dat"] [int verbose=1]</em>Writes out a genotype abundance histogram.</li>
	<li><strong><a name="PrintGermlineData"></a>PrintGermlineData</strong>
<em>[string fname="germline.dat"]</em></li>
	<li><strong><a name="PrintGroupIds"></a>PrintGroupIds</strong>
<em>[string fname="groupids.dat"]</em></li>
	<li><strong><a name="PrintGroupsFormedData"></a>PrintGroupsFormedData</strong>
<em>[string fname="groupformation.dat"]</em></li>
	<li><strong><a name="PrintGroupTolerance"></a>PrintGroupTolerance</strong>
<em>[string fname="grouptolerance.dat"]</em></li>
	<li><strong><a name="PrintHGTData"></a>PrintHGTData</strong>
<em>[string fname="hgt.dat"]</em></li>
	<li><strong><a name="PrintHostDepthHistogram"></a>PrintHostDepthHistogram</strong>
<em>[string fname="depth_host_histogram.dat"]</em></li>
	<li><strong><a name="PrintHostPhenotypeData"></a>PrintHostPhenotypeData</strong>
<em>[string fname="host_phenotype_count.dat"]</em></li>
	<li><strong><a name="PrintHostTasksData"></a>PrintHostTasksData</strong>
<em>[string fname="host_tasks.dat"]</em></li>
	<li><strong><a name="PrintInstructionAbundanceHistogram"></a>PrintInstructionAbundanceHistogram</strong>
<em>[string fname="instruction_histogram-${inst_set}.dat"] [string inst_set]</em>Appends a line containing the bulk count (abundance) of each instruction
in the population onto a file.</li>
	<li><strong><a name="PrintInstructionData"></a>PrintInstructionData</strong>
<em>[string fname="instruction-${inst_set}.dat"] [string inst_set]</em>Print the by-organisms counts of what instructions they _successfully_ executed
beteween birth and divide. Prior to their first divide, organisms values for their parents.</li>
	<li><strong><a name="PrintInternalTasksData"></a>PrintInternalTasksData</strong>
<em>[string fname="in_tasks.dat"]</em>Print the number of organisms that have performed each task using internal resources.Note that tasks performed using internal resources are also counted as tasks perfomed (by <a href="#PrintTasksData">PrintTasksData</a>), so that if you wish to know the number of tasks performed <em>not</em> using internal resources you must do some subtraction.</li>
	<li><strong><a name="PrintInternalTasksQualData"></a>PrintInternalTasksQualData</strong>
<em>[string fname="in_tasks_quality.dat"]</em>Print the total quality of each task when performed using internal resources. (See <a href="#PrintTasksQualData">PrintTasksQualData</a> for more about task quality.</li>
	<li><strong><a name="PrintInterruptData"></a>PrintInterruptData</strong>
<em>[string fname="interrupt.dat"]</em></li>
	<li><strong><a name="PrintLineageCounts"></a>PrintLineageCounts</strong>
<em>[string fname="lineage_counts.dat"]\n WARNING: This will only have the appropriate header if all lineages are present before this action is run for the first time.</em></li>
	<li><strong><a name="PrintLineageTotals"></a>PrintLineageTotals</strong></li>
	<li><strong><a name="PrintLogFitnessHistogram"></a>PrintLogFitnessHistogram</strong>
<em>Parameters: &lt;filename&gt; &lt;mode&gt; &lt;min&gt; &lt;step&gt; &lt;max&gt;</em>Print a histogram of organism fitnesses in the current population.This action will only work in run mode.<kbd>mode</kbd> may be {<kbd>CURRENT, ACTUAL, TESTCPU</kbd>}, where<kbd>CURRENT</kbd> uses the current phenotype value of fitness</li>
</ul>
<kbd>ACTUAL</kbd>uses the current merit and the true gestation time (via test cpu calculation)
<kbd>TESTCPU</kbd>uses the test cpu measurement.
<kbd>lower_bound, step, upper_bound</kbd> are log10 values for the individual histogram bins.

&nbsp;
<ul>
	<li><strong><a name="PrintMarketData"></a>PrintMarketData</strong>
<em>[string fname="market.dat"]</em></li>
	<li><strong><a name="PrintMatingDisplayData"></a>PrintMatingDisplayData</strong>
<em>[string fname="mating_display_data.dat"]</em></li>
	<li><strong><a name="PrintMatingTypeHistogram"></a>PrintMatingTypeHistogram</strong>
<em>[string fname="mating_type_histogram.dat"]</em></li>
	<li><strong><a name="PrintMessageData"></a>PrintMessageData</strong>
<em>[string fname="message.dat"]</em></li>
	<li><strong><a name="PrintMessageLog"></a>PrintMessageLog</strong>
<em>[string fname="message_log.dat"]</em></li>
	<li><strong><a name="PrintMigrationData"></a>PrintMigrationData</strong>
<em>[string fname="migration.dat"]</em></li>
	<li><strong><a name="PrintMultiProcessData"></a>PrintMultiProcessData</strong>
<em>[string fname="multiprocess.dat"]</em></li>
	<li><strong><a name="PrintMutationRateData"></a>PrintMutationRateData</strong>
<em>[string fname="mutation_rates.dat"]</em>Output (regular and log) statistics about individual copy mutation rates
(aver, stdev, skew, cur). Useful only when mutation rate is set per organism.</li>
	<li><strong><a name="PrintNewReactionData"></a>PrintNewReactionData</strong>
<em>[string fname=" newreactions.dat "]</em>Print number of times the particular reaction has newly appeared in the population since
the last time this datum was printed. Newly appeared is defined as an organism triggering
a reaction that was not triggered by its parent.</li>
	<li><strong><a name="PrintNewTasksData"></a>PrintNewTasksData</strong>
<em>[string fname="newtasks.dat "]</em>Print number of times the particular task has newly appeared in the population since
the last time this datum was printed. Newly appeared is defined as an organism executing
a task that was not executed by its parent.</li>
	<li><strong><a name="PrintNewTasksDataPlus"></a>PrintNewTasksDataPlus</strong>
<em>[string fname="newtasksplus.dat "]</em></li>
	<li><strong><a name="PrintNumOrgsInDeme"></a>PrintNumOrgsInDeme</strong>
<em>No Arguments</em></li>
	<li><strong><a name="PrintNumOrgsKilledData"></a>PrintNumOrgsKilledData</strong>
<em>[string fname="orgs_killed.dat"]</em></li>
	<li><strong><a name="PrintOpinionsSetPerDeme"></a>PrintOpinionsSetPerDeme</strong>
<em>[string fname="opinions_set.dat"]</em></li>
	<li><strong><a name="PrintOrganismLocation"></a>PrintOrganismLocation</strong>
<em>[string fname="location.dat"]</em></li>
	<li><strong><a name="PrintParasiteData"></a>PrintParasiteData</strong>
<em>[string fname="parasite.dat"]</em></li>
	<li><strong><a name="PrintParasiteDepthHistogram"></a>PrintParasiteDepthHistogram</strong>
<em>[string fname="depth_parasite_histogram.dat"]</em></li>
	<li><strong><a name="PrintParasitePhenotypeData"></a>PrintParasitePhenotypeData</strong>
<em>[string fname="parasite_phenotype_count.dat"]</em></li>
	<li><strong><a name="PrintParasiteTasksData"></a>PrintParasiteTasksData</strong>
<em>[string fname="parasite_tasks.dat"]</em></li>
	<li><strong><a name="PrintPerDemeGenPerFounderData"></a>PrintPerDemeGenPerFounderData</strong>
<em>[string fname="deme_gen_between_founders.dat"]</em></li>
	<li><strong><a name="PrintPerDemeReactionData"></a>PrintPerDemeReactionData</strong>
<em>[string fname="per_deme_reactions.dat"]</em></li>
	<li><strong><a name="PrintPerDemeTasksData"></a>PrintPerDemeTasksData</strong>
<em>[string fname="per_deme_tasks.dat"]</em></li>
	<li><strong><a name="PrintPerDemeTasksExeData"></a>PrintPerDemeTasksExeData</strong>
<em>[string fname="per_deme_tasks_exe.dat"]</em></li>
	<li><strong><a name="PrintPhenotypeData"></a>PrintPhenotypeData</strong>
<em>[string fname="phenotype_count.dat"]</em>[<span class="cmdarg">string filename='phenotype_count.dat'</span>]
Print the number of phenotypes based on tasks executed this update. Executing
a task any number of times is considered the same as executing it once.</li>
	<li><strong><a name="PrintPhenotypeStatus"></a>PrintPhenotypeStatus</strong>
<em>[string fname="phenotype_status.dat"]</em></li>
	<li><strong><a name="PrintPhenotypicPlasticity"></a>PrintPhenotypicPlasticity</strong>
<em>[string filename="phenplast"] [int num_trials=1000]</em>This function will provided detailed information about the phenotypic varients
of the current population/batch by running each genome through a test cpu <kbd>num_trials</kbd> times.
If this command is executed in run mode, the
<kbd>filename</kbd> will be appeneded with <kbd>-Update.dat</kbd> where <kbd>Update</kbd>
is the current update. In analyze mode, the default file is merely phenplast.dat.
The output file contains the following: id, parent_id, phenotypic_varient_number, frequency, fitness, merit,
gestation_time, and task counts for each phenotypic variant of each genotype.</li>
	<li><strong><a name="PrintPlasticGenotypeSummary"></a>PrintPlasticGenotypeSummary</strong>
<em>[string filename="genotype_plsticity.dat"]</em></li>
	<li><strong><a name="PrintPopulationDistanceData"></a>PrintPopulationDistanceData</strong>
<em>[string creature="START_ORGANISM"] [string fname=""] [int save_genotypes=0]</em></li>
	<li><strong><a name="PrintPredatorAverageData"></a>PrintPredatorAverageData</strong>
<em>[string fname="predator_average.dat"]</em></li>
	<li><strong><a name="PrintPredatorErrorData"></a>PrintPredatorErrorData</strong>
<em>[string fname="predator_error.dat"]</em></li>
<li><strong><a name="PrintMinPreyFailedAttacks"></a>PrintMinPreyFailedAttacks</strong>
<em>[string fname="failed_attacks.dat"]</em></li>
	<li><strong><a name="PrintPredatorInstructionData"></a>PrintPredatorInstructionData</strong>
<em>[string fname="predator_instruction-${inst_set}.dat"] [string inst_set]</em></li>
	<li><strong><a name="PrintPredatorVarianceData"></a>PrintPredatorVarianceData</strong>
<em>[string fname="predator_variance.dat"]</em></li>
	<li><strong><a name="PrintPredicatedMessages"></a>PrintPredicatedMessages</strong>
<em>[string fname="messages.dat"]</em></li>
	<li><strong><a name="PrintPreyAverageData"></a>PrintPreyAverageData</strong>
<em>[string fname="prey_average.dat"]</em></li>
	<li><strong><a name="PrintPreyErrorData"></a>PrintPreyErrorData</strong>
<em>[string fname="prey_error.dat"]</em></li>
	<li><strong><a name="PrintPreyInstructionData"></a>PrintPreyInstructionData</strong>
<em>[string fname="prey_instruction-${inst_set}.dat"] [string inst_set]</em></li>
	<li><strong><a name="PrintPreyVarianceData"></a>PrintPreyVarianceData</strong>
<em>[string fname="prey_variance.dat"]</em></li>
	<li><strong><a name="PrintProfilingData"></a>PrintProfilingData</strong>
<em>[string fname="profiling.dat"]</em></li>
	<li><strong><a name="PrintReactionData"></a>PrintReactionData</strong>
<em>[string fname="reactions.dat"]</em></li>
	<li><strong><a name="PrintReactionExeData"></a>PrintReactionExeData</strong>
<em>[string fname="reactions_exe.dat"]</em></li>
	<li><strong><a name="PrintReactionRewardData"></a>PrintReactionRewardData</strong>
<em>[string fname="reaction_reward.dat"]</em></li>
	<li><strong><a name="PrintRelativeFitnessHistogram"></a>PrintRelativeFitnessHistogram</strong>
<em>[filename] [fit_mode] [hist_min] [hist_step] [hist_max]</em>Print a histogram of parent-relative fitness ratios for each coalescence clade in the population.This action will only work in run mode.<kbd>mode</kbd> may be {<kbd>CURRENT, ACTUAL, TESTCPU</kbd>}, where<kbd>CURRENT</kbd> uses the current phenotype value of fitness</li>
</ul>
<kbd>ACTUAL</kbd>uses the current merit and the true gestation time (via test cpu calculation)
<kbd>TESTCPU</kbd>uses the test cpu measurement.
<kbd>lower_bound, step, upper_bound</kbd> are values for the individual histogram bins.

&nbsp;
<ul>
<li><strong><a name="PrintReproData">PrintReproData</a></strong>
<em>No arguments</em></li>
    Record and print some data up to first reproduction for every org alive now.</li>
	<li><strong><a name="PrintReputationData"></a>PrintReputationData</strong>
<em>[string fname="reputation.dat"]</em></li>
	<li><strong><a name="PrintResourceData"></a>PrintResourceData</strong>
<em>[string fname="resource.dat"] [string print_maps="1"]</em>Print the current counts of each resource available to the population. This uses
the environment configuration to determine what resources are in use. Also optionally creates
separate files <kbd>resource_<em>resource_name</em>.m</kbd> (in a format that is
designed to be read into Matlab) for each spatial resource. Uses 1 as default but you can put 0 to only print resource.dat and save space.</li>
	<li><strong><a name="PrintSenseData"></a>PrintSenseData</strong>
<em>[string fname="sense.dat"]</em></li>
	<li><strong><a name="PrintSenseExeData"></a>PrintSenseExeData</strong>
<em>[string fname="sense_exe.dat"]</em></li>
	<li><strong><a name="PrintShadedAltruists"></a>PrintShadedAltruists</strong>
<em>[string fname="shadedaltruists.dat"]</em></li>
	<li><strong><a name="PrintSimpleConsensusData"></a>PrintSimpleConsensusData</strong>
<em>[string fname="simple_consensus.dat"]</em></li>
	<li><strong><a name="PrintSleepData"></a>PrintSleepData</strong>
<em>[string fname="sleep.dat"]</em></li>
	<li><strong><a name="PrintSpeciesAbundanceHistogram"></a>PrintSpeciesAbundanceHistogram</strong>Writes out a species abundance histogram.</li>
	<li><strong><a name="PrintStatsData"></a>PrintStatsData</strong>
<em>[string fname="stats.dat"]</em>Print all of the miscellanous population statistics.</li>
	<li><strong><a name="PrintStringMatchData"></a>PrintStringMatchData</strong>
<em>[string fname="stringmatch.dat"]</em></li>
	<li><strong><a name="PrintSuccessfulMates"></a>PrintSuccessfulMates</strong>
<em>[string fname="mates/mates-XXXX.dat"]</em></li>
	<li><strong><a name="PrintSynchronizationData"></a>PrintSynchronizationData</strong>
<em>[string fname="sync.dat"]</em></li>
	<li><strong><a name="PrintTargets"></a>PrintTargets</strong>
<em>[string fname="targets.dat"]</em></li>
	<li><strong><a name="PrintTaskProbHistogram"></a>PrintTaskProbHistogram</strong>
<em>[filename=pp_histogram.dat] [weightbycpus=0]</em></li>
	<li><strong><a name="PrintTasksData"></a>PrintTasksData</strong>
<em>[string fname="tasks.dat"]</em>Print the number of organisms that are able to perform each task. This uses the
environment configuration to determine what tasks are in use.</li>
	<li><strong><a name="PrintTasksExeData"></a>PrintTasksExeData</strong>
<em>[string fname="tasks_exe.dat"]</em>Print number of times the particular task has been executed this update.</li>
	<li><strong><a name="PrintTaskSnapshot"></a>PrintTaskSnapshot</strong>
<em>[string fname=""]</em>Run all organisms in the population through test cpus and print out the
number of tasks each can perform.</li>
	<li><strong><a name="PrintTasksQualData"></a>PrintTasksQualData</strong>
<em>[string fname="tasks_quality.dat"]</em>Print the total quality of each task. By default a successful task is valued
as 1.0. Some tasks, however, can grant partial values and/or special bonuses
via the quality value.</li>
	<li><strong><a name="PrintThreadsData"></a>PrintThreadsData</strong>
<em>[string fname="threads.dat"]</em></li>
	<li><strong><a name="PrintTimeData"></a>PrintTimeData</strong>
<em>[string fname="time.dat"]</em>Print all of the timing related statistics.</li>
	<li><strong><a name="PrintToleranceData"></a>PrintToleranceData</strong>
<em>[string fname="tolerance.dat"]</em></li>
	<li><strong><a name="PrintToleranceInstructionData"></a>PrintToleranceInstructionData</strong>
<em>[string fname="toleranceinstruction.dat"]</em></li>

<li><strong><a name="PrintTopNavTrace"></a>PrintTopNavTrace</strong>
<em>No arguments</em></li>
<p>
  Record and print some nav data up to first reproduction for best of orgs alive now, including trace execution,
  locations, and facings. Will print these data for the org among those with the highest reaction achieved By
  time of reproduction in shortest amount of time (as measured by cycles). Will print nothing if any of the 
  candidate orgs are still alive when avida exits and no FlushTopNavTrace events were called.
    </p>
</li>

	<li><strong><a name="PrintTotalsData"></a>PrintTotalsData</strong>
<em>[string fname="totals.dat"]</em>Print various totals for the entire length of the run (for example, the total number of
organisms ever).</li>
	<li><strong><a name="PrintVarianceData"></a>PrintVarianceData</strong>
<em>[string fname="variance.dat"]</em>Print all of the variances of the average population statistics.</li>
	<li><strong><a name="PrintViableTasksData"></a>PrintViableTasksData</strong>
<em>[string fname="viable_tasks.dat"]</em></li>
	<li><strong><a name="PrintWinningDeme"></a>PrintWinningDeme</strong>
<em>[string fname="deme_winners.dat"]</em></li>
	<li><strong><a name="SaveDemeFounders"></a>SaveDemeFounders</strong>
<em>[string fname=""]</em></li>
	<li><strong><a name="SetVerbose"></a>SetVerbose</strong>
<em>[string verbosity=""]</em>Change the level of output verbosity. Verbose messages will print all
of the details of what is happening to the screen. Minimal messages
will only briefly state the process being run. Verbose messages are
recommended if you're in interactive analysis mode. When no arguments
are supplied, action will toggle between NORMAL and ON.Levels: SILENT, NORMAL, ON, DETAILS, DEBUG</li>
	<li><strong><a name="TestDominant"></a>TestDominant</strong>
<em>[string fname="dom-test.dat"]</em></li>
	<li><strong><a name="VERBOSE"></a>VERBOSE</strong>
<em>[string verbosity=""]</em></li>
</ul>
&nbsp;

&nbsp;
<h2><a name="SaveLoadActions"></a>Save Load Actions</h2>
<ul>
<li><p>
  <strong><a name="LoadPopulation">LoadPopulation</a></strong>
  <i>&lt;cString fname&gt; [int update=-1] [int cellid_offset=0] [int lineage_offset=0] [bool load_groups=0] [bool load_birth_cells=0] [bool load_avatars=0] [bool load_rebirth]</i>
  </p>
  <p>
    Sets up a population based on a save file such as written out by
  SavePopulation. It is also possible to append a history file to the
  save file, in order to preserve the history of a previous run.<br>
  <b><i>update</i></b> allows user to set the current update number to a new value<br>
  <b><i>load_groups</i></b> allows users to load population files containing individual 
  group ids (opinions) and forager types (aka saved populations with save_groups = 1)<br>
  <i>load_birth_cells</i> allows users to drop each org into it's original birth cell. This
  can be important for populations in spatial environments where state information
  would have been collected as the org moved around the world.<br>
  e.g to load a population with birth cells and group ids, but without cell, lineage, or update offsets:<br>
  i LoadPopulation -1 0 0 1 1 0<br>
  <i>load_rebirth</i> will override load_groups, load_birth_cells, load avatars and inject orgs into their saved birth cells, 
  put avatars in their birth cells (if avatars are on), assign parent's merit to org (if inherit merit is on) and assign the 
  parent's forage target if the parent was a 'teacher' <br>
  i LoadPopulation -1 0 0 0 0 0 1<br>
  </p>
</li>

	<li><strong><a name="SaveFlameData"></a>SaveFlameData</strong>
<em>[string filename="flame"]</em></li>
	<li><strong><a name="SavePopulation"></a>SavePopulation</strong>
<em>[string filename="detail"] [boolean save_historic=1] [boolean save_groups=0] [boolean save_avatars=0] [boolean save_rebirth=0] </em>Save the genotypes and lots of statistics about the population to the
file specified; if no filename is given, use the name
<kbd>detail-<em>update</em>.pop</kbd>. As with clones, the update number
allows a single event to produce many detail files. The details are used
to collect crossection data about the population.
The filename is a string that is used to prefix the update number and file extension, e.g. detail-100.spop.
The save_historic option determines whether the action saves the full history for the current population.
  <i>save_groups</i> will append data on current group ids, current forage targets 
  and the cell orgs were born into for each occurence of each genotype
  Using <i>save_rebirth</i> will save additional information about the birth of the organism which
  would be required to 'repeat' the birth of the organism as if it was still in the population (for
  behavioral trials, etc):
  parent_ft, parent is teacher, parent merit (out to 4 dec places)
  Using save_rebirth will save all possible columns (i.e. will save all save_groups + all save_avatars data even if
  those flags are off).
Save canvas [deprecated] will save information about the canvas location, birth location, and canvas number used by the orgs. If save_canvas is true, save_avatars will be set to false, save_groups will be set to true, and save_rebirth will be set to true.
</li>
</ul>
&nbsp;
<h2><a name="CreateAction"></a>Creating an Action</h2>
The action source code is contained in the source/action directory.
Each of the individual <a href="#ActionCategories">action categories</a> has its own source code files (e.g. Landcape Actions are located in the LandscapeActions files).

Each action is derrived from the cAction class. Briefly, to get an action to work you must create a child class that has a Process and GetDescription function defined as well as a constructor. You must also register this new class with the action library.

So, with that quick review of what must be done, here is a step by step guide to creating an action:
<ol>
	<li>Identify which of the action categories your action should be assigned to. There are six different action categories described <a href="#ActionCategories">above</a>. Each category has a similar means of creating a new action, but do note that some action commands are generated via macros defined at the top of the files. For instance, in the PrintActions file, you will notice a number of STATS_OUT_FILE macros being used to generate rather repetitively coded standard output files.</li>
	<li>Create a new class in the file that follows proper naming conventions. Any class should begin with "cAction" and be followed by the name of the action command you will register with the library. For instance, if we were to create a new command "MyAction", we'd name the class cActionMyAction. Below is a stub for this new action class:
<pre>class cActionMyAction : public cAction
{
	private:
		// Private data members for this action
	public:
		cActionMyAction(cWorld* world, const cString&amp; args) : cAction(world, args) { ; }

		static const cString GetDescription() { return "Arguments: My Arguments"; }

		void Process(cAvidaContext&amp; ctx)
		{
			//Perform whatever processing is needed when the action is triggered.
		}
};</pre>
</li>
	<li>Define the private data members, constructor, description string in GetDescription, and the Process function. Any arguments that you specify after the action name in the events configuration will be passed to your new class via the args argument in the constructor. (If you want more documentation for your actions than just the arguments, see the final step in this list.</li>
	<li>Register the new action with the action library. At the bottom of each action definitions file, there are the commands that register the individual actions with the action library. In the PrintActions.cc file, for instance, this function is called RegisterPrintActions.To register our example action "MyAction", we'd write:
<pre>action_lib-&gt;Register&lt;cActionMyAction&gt;("MyAction");</pre>
&nbsp;</li>
	<li>Test your action.</li>
	<li>Add a ==== Action <em>action name</em> ==== line in
source/utils/make_actions_html/actions_source_info file</li>
</ol>